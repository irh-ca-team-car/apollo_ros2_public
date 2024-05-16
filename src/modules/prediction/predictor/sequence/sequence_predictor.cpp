/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/prediction/predictor/sequence/sequence_predictor.h"

#include <limits>
#include <memory>

#include "modules/common/proto/geometry.pb.h"
#include "modules/prediction/common/prediction_gflags.h"
#include "modules/prediction/container/container_manager.h"
#include "modules/prediction/container/pose/pose_container.h"

namespace apollo
{
    namespace prediction
    {

        using apollo::common::PathPoint;
        using apollo::common::Point3D;
        using apollo::common::TrajectoryPoint;
        using apollo::hdmap::LaneInfo;
        using apollo_msgs::msg::ApollopredictionLaneSequence;
        bool SequencePredictor::Predict(
            const ADCTrajectoryContainer *adc_trajectory_container, Obstacle *obstacle,
            ObstaclesContainer *obstacles_container)
        {
            (void)adc_trajectory_container;
            (void)obstacles_container;
            Clear();

            CHECK_NOTNULL(obstacle);
            CHECK_GT(obstacle->history_size(), 0U);
            return true;
        }

        void SequencePredictor::Clear() { Predictor::Clear(); }

        std::string SequencePredictor::ToString(const ApollopredictionLaneSequence &sequence)
        {
            std::string str_lane_sequence = "";
            if (sequence.lanesegment.size() > 0)
            {
                str_lane_sequence += sequence.lanesegment.at(0).laneid;
            }
            for (size_t i = 1; i < sequence.lanesegment.size(); ++i)
            {
                str_lane_sequence += ("->" + sequence.lanesegment.at(i).laneid);
            }
            return str_lane_sequence;
        }

        void SequencePredictor::FilterLaneSequences(
            const Feature &feature, const std::string &lane_id,
            const Obstacle *ego_vehicle_ptr,
            const ADCTrajectoryContainer *adc_trajectory_container,
            std::vector<bool> *enable_lane_sequence)
        {
            if ((feature.lane == Lane()) || (feature.lane.lanegraph == LaneGraph()))
            {
                return;
            }
            const LaneGraph &lane_graph = feature.lane.lanegraph;
            size_t num_lane_sequence = lane_graph.lanesequence.size();
            std::vector<LaneChangeType> lane_change_type(num_lane_sequence,
                                                         LaneChangeType::INVALID);
            std::pair<int, double> change(-1, -1.0);
            std::pair<int, double> all(-1, -1.0);

            /**
   * Filter out those obstacles that are close to the ADC
   * so that we will ignore them and drive normally unless
   * they really kick into our lane.
   */
            for (size_t i = 0; i < num_lane_sequence; ++i)
            {
                const ApollopredictionLaneSequence &sequence = lane_graph.lanesequence.at(i);
                if (sequence.lanetype == apollo::hdmap::Lane::PARKING)
                {
                    (*enable_lane_sequence)[i] = false;
                    ADEBUG << "Ignore lane sequence [" << ToString(sequence) << "].";
                    continue;
                }
                lane_change_type[i] = GetLaneChangeType(lane_id, sequence);

                if (lane_change_type[i] != LaneChangeType::LEFT &&
                    lane_change_type[i] != LaneChangeType::RIGHT &&
                    lane_change_type[i] != LaneChangeType::ONTO_LANE)
                {
                    ADEBUG << "Ignore lane sequence [" << ToString(sequence) << "].";
                    continue;
                }

                // The obstacle has interference with ADC within a small distance
                double distance = GetLaneChangeDistanceWithADC(sequence, ego_vehicle_ptr,
                                                               adc_trajectory_container);
                ADEBUG << "Distance to ADC " << std::fixed << std::setprecision(6)
                       << distance;
                if (distance > 0.0 && distance < FLAGS_lane_change_dist)
                {
                    bool obs_within_its_own_lane = true;
                    for (size_t j = 0; j < feature.polygonpoint.size(); j++)
                    {
                        Eigen::Vector2d position(feature.polygonpoint.at(j).x,
                                                 feature.polygonpoint.at(j).y);
                        std::shared_ptr<const LaneInfo> lane_info =
                            PredictionMap::LaneById(lane_id);
                        if (lane_info == nullptr)
                        {
                            obs_within_its_own_lane = false;
                            break;
                        }

                        double lane_s = 0.0;
                        double lane_l = 0.0;
                        PredictionMap::GetProjection(position, lane_info, &lane_s, &lane_l);

                        double left = 0.0;
                        double right = 0.0;
                        lane_info->GetWidth(lane_s, &left, &right);

                        if (lane_l > left || lane_l < -right)
                        {
                            obs_within_its_own_lane = false;
                            break;
                        }
                    }

                    if (obs_within_its_own_lane)
                    {
                        (*enable_lane_sequence)[i] = false;
                        ADEBUG << "Filter trajectory [" << ToString(sequence)
                               << "] due to small distance " << distance << ".";
                    }
                }
            }

            /**
   * Pick the most probable lane-sequence and lane-change
   */
            for (size_t i = 0; i < num_lane_sequence; ++i)
            {
                const auto &sequence = lane_graph.lanesequence.at(i);

                if (!(*enable_lane_sequence)[i])
                {
                    ADEBUG << "Disabled lane sequence [" << ToString(sequence) << "].";
                    continue;
                }

                double probability = sequence.probability;
                if (LaneSequenceWithMaxProb(lane_change_type[i], probability, all.second))
                {
                    all.first = i;
                    all.second = probability;
                }
                if (LaneChangeWithMaxProb(lane_change_type[i], probability,
                                          change.second))
                {
                    change.first = i;
                    change.second = probability;
                }
            }

            double lane_sequence_threshold = FLAGS_lane_sequence_threshold_cruise;
            if (feature.junctionfeature != JunctionFeature())
            {
                lane_sequence_threshold = FLAGS_lane_sequence_threshold_junction;
            }

            for (size_t i = 0; i < num_lane_sequence; ++i)
            {
                const auto &sequence = lane_graph.lanesequence.at(i);

                if (!(*enable_lane_sequence)[i])
                {
                    ADEBUG << "Disabled lane sequence [" << ToString(sequence) << "].";
                    continue;
                }

                double probability = sequence.probability;
                if (probability < lane_sequence_threshold && (int)i != all.first)
                {
                    (*enable_lane_sequence)[i] = false;
                }
                else if (change.first >= 0 && change.first < (int)num_lane_sequence &&
                         (lane_change_type[i] == LaneChangeType::LEFT ||
                          lane_change_type[i] == LaneChangeType::RIGHT) &&
                         lane_change_type[i] != lane_change_type[change.first])
                {
                    (*enable_lane_sequence)[i] = false;
                }
            }
        }

        SequencePredictor::LaneChangeType SequencePredictor::GetLaneChangeType(
            const std::string &lane_id, const ApollopredictionLaneSequence &lane_sequence)
        {
            if (lane_id.empty())
            {
                return LaneChangeType::ONTO_LANE;
            }

            std::string lane_change_id = lane_sequence.lanesegment.at(0).laneid;
            if (lane_id == lane_change_id)
            {
                return LaneChangeType::STRAIGHT;
            }
            else
            {
                auto ptr_change_lane = PredictionMap::LaneById(lane_change_id);
                auto ptr_current_lane = PredictionMap::LaneById(lane_id);
                if (PredictionMap::IsLeftNeighborLane(ptr_change_lane, ptr_current_lane))
                {
                    return LaneChangeType::LEFT;
                }
                else if (PredictionMap::IsRightNeighborLane(ptr_change_lane,
                                                            ptr_current_lane))
                {
                    return LaneChangeType::RIGHT;
                }
            }
            return LaneChangeType::INVALID;
        }

        double SequencePredictor::GetLaneChangeDistanceWithADC(
            const ApollopredictionLaneSequence &lane_sequence, const Obstacle *ego_vehicle_ptr,
            const ADCTrajectoryContainer *adc_trajectory_container)
        {
            if (!adc_trajectory_container->HasOverlap(lane_sequence))
            {
                ADEBUG << "The sequence [" << ToString(lane_sequence)
                       << "] has no overlap with ADC.";
                return std::numeric_limits<double>::max();
            }

            Eigen::Vector2d adc_position;
            if (ego_vehicle_ptr != nullptr && ego_vehicle_ptr->history_size() > 0)
            {
                const auto &position = ego_vehicle_ptr->latest_feature().position;
                adc_position[0] = position.x;
                adc_position[1] = position.y;

                std::string obstacle_lane_id = lane_sequence.lanesegment.at(0).laneid;
                double obstacle_lane_s = lane_sequence.lanesegment.at(0).starts;
                double lane_s = 0.0;
                double lane_l = 0.0;
                if (PredictionMap::GetProjection(adc_position,
                                                 PredictionMap::LaneById(obstacle_lane_id),
                                                 &lane_s, &lane_l))
                {
                    ADEBUG << "Distance with ADC is " << std::fabs(lane_s - obstacle_lane_s);
                    return obstacle_lane_s - lane_s;
                }
            }

            ADEBUG << "Invalid ADC pose.";
            return std::numeric_limits<double>::max();
        }

        bool SequencePredictor::LaneSequenceWithMaxProb(const LaneChangeType &type,
                                                        const double probability,
                                                        const double max_prob)
        {
            if (probability > max_prob)
            {
                return true;
            }
            else
            {
                double prob_diff = std::fabs(probability - max_prob);
                if (prob_diff <= std::numeric_limits<double>::epsilon() &&
                    type == LaneChangeType::STRAIGHT)
                {
                    return true;
                }
            }
            return false;
        }

        bool SequencePredictor::LaneChangeWithMaxProb(const LaneChangeType &type,
                                                      const double probability,
                                                      const double max_prob)
        {
            if (type == LaneChangeType::LEFT || type == LaneChangeType::RIGHT)
            {
                if (probability > max_prob)
                {
                    return true;
                }
            }
            return false;
        }

        void SequencePredictor::DrawConstantAccelerationTrajectory(
            const Obstacle &obstacle, const ApollopredictionLaneSequence &lane_sequence,
            const double total_time, const double period, const double acceleration,
            std::vector<TrajectoryPoint> *points)
        {
            const Feature &feature = obstacle.latest_feature();
           

            Eigen::Vector2d position(feature.position.x, feature.position.y);
            double speed = feature.speed;

            size_t lane_segment_index = 0;
            std::string lane_id =
                lane_sequence.lanesegment.at(lane_segment_index).laneid;
            std::shared_ptr<const LaneInfo> lane_info = PredictionMap::LaneById(lane_id);
            double lane_s = 0.0;
            double lane_l = 0.0;
            if (!PredictionMap::GetProjection(position, lane_info, &lane_s, &lane_l))
            {
                AERROR << "Failed in getting lane s and lane l";
                return;
            }
            size_t total_num = static_cast<size_t>(total_time / period);
            for (size_t i = 0; i < total_num; ++i)
            {
                double relative_time = static_cast<double>(i) * period;
                Eigen::Vector2d point;
                double theta = M_PI;
                if (!PredictionMap::SmoothPointFromLane(lane_id, lane_s, lane_l, &point,
                                                        &theta))
                {
                    AERROR << "Unable to get smooth point from lane [" << lane_id
                           << "] with s [" << lane_s << "] and l [" << lane_l << "]";
                    break;
                }
                TrajectoryPoint trajectory_point;
                PathPoint path_point;
                path_point.set__x(point.x());
                path_point.set__y(point.y());
                path_point.set__z(0.0);
                path_point.set__theta(theta);
                path_point.set__laneid(lane_id);
                trajectory_point.pathpoint=(path_point);
                trajectory_point.set__v(speed);
                trajectory_point.set__a(0.0);
                trajectory_point.set__relativetime(relative_time);
                points->emplace_back(std::move(trajectory_point));

                if (speed < FLAGS_double_precision)
                {
                    continue;
                }

                lane_s += speed * period + 0.5 * acceleration * period * period;
                speed += acceleration * period;

                while (lane_s > PredictionMap::LaneById(lane_id)->total_length() &&
                       lane_segment_index + 1 < lane_sequence.lanesegment.size())
                {
                    lane_segment_index += 1;
                    lane_s = lane_s - PredictionMap::LaneById(lane_id)->total_length();
                    lane_id = lane_sequence.lanesegment.at(lane_segment_index).laneid;
                }

                lane_l *= FLAGS_go_approach_rate;
            }
        }

        double SequencePredictor::GetLaneSequenceCurvatureByS(
            const ApollopredictionLaneSequence &lane_sequence, const double s)
        {
            CHECK_GT(lane_sequence.lanesegment.size(), 0);
            double lane_s = s + lane_sequence.lanesegment.at(0).starts;
            for (const LaneSegment &lane_segment : lane_sequence.lanesegment)
            {
                std::string lane_id = lane_segment.laneid;
                std::shared_ptr<const LaneInfo> lane_info_ptr =
                    PredictionMap::LaneById(lane_id);
                double lane_length = lane_info_ptr->total_length();
                if (lane_s > lane_length + FLAGS_double_precision)
                {
                    lane_s -= lane_length;
                }
                else
                {
                    return lane_info_ptr->Curvature(lane_s);
                }
            }
            ADEBUG << "Outside lane sequence range, use 0.0 to approximate.";
            return 0.0;
        }

        bool SequencePredictor::GetLongitudinalPolynomial(
            const Obstacle &obstacle, const ApollopredictionLaneSequence &lane_sequence,
            const std::pair<double, double> &lon_end_vt,
            std::array<double, 5> *coefficients)
        {
            // Sanity check.
            CHECK_NOTNULL(coefficients);
            CHECK_GT(obstacle.history_size(), 0U);
            CHECK_GT(lane_sequence.lanesegment.size(), 0);
            CHECK_GT(lane_sequence.lanesegment.at(0).lanepoint.size(), 0);

            // Get obstacle info.
            const Feature &feature = obstacle.latest_feature();
            double theta = feature.velocityheading;
            double v = feature.speed;
            double a = 0.0;

            // Get lane info.
            if (FLAGS_enable_lane_sequence_acc && lane_sequence.acceleration!=0)
            {
                a = lane_sequence.acceleration;
            }
            int lane_seg_start_idx = lane_sequence.adclanesegmentidx;
            size_t lane_point_start_idx =
                lane_sequence.lanesegment.at(lane_seg_start_idx).adclanepointidx;
            if (lane_point_start_idx >=
                lane_sequence.lanesegment.at(lane_seg_start_idx).lanepoint.size())
            {
                lane_point_start_idx =
                    lane_sequence.lanesegment.at(lane_seg_start_idx).lanepoint.size() - 1;
            }
            double lane_heading = lane_sequence.lanesegment.at(lane_seg_start_idx)
                                      .lanepoint.at(lane_point_start_idx)
                                      .heading;

            // Set the initial conditions for the diff. eqn.
            double s0 = 0.0;
            double ds0 = v * std::cos(theta - lane_heading);
            double dds0 = a * std::cos(theta - lane_heading);
            // double min_end_speed = std::min(FLAGS_still_obstacle_speed_threshold, ds0);
            // double ds1 = std::max(min_end_speed, ds0 + dds0 * time_to_end_state);
            double ds1 = lon_end_vt.first;
            double dds1 = 0.0;
            double p = lon_end_vt.second; // time to lon end state

            // Solve for the coefficients.
            coefficients->operator[](0) = s0;
            coefficients->operator[](1) = ds0;
            coefficients->operator[](2) = 0.5 * dds0;
            double b0 = ds1 - dds0 * p - ds0;
            double b1 = dds1 - dds0;
            double p2 = p * p;
            double p3 = p2 * p;
            coefficients->operator[](3) = b0 / p2 - b1 / 3.0 / p;
            coefficients->operator[](4) = -0.5 / p3 * b0 + 0.25 / p2 * b1;
            return true;
        }

        bool SequencePredictor::GetLateralPolynomial(
            const Obstacle &obstacle, const ApollopredictionLaneSequence &lane_sequence,
            const double time_to_end_state, std::array<double, 4> *coefficients)
        {
            // Sanity check.
            CHECK_NOTNULL(coefficients);
            CHECK_GT(obstacle.history_size(), 0U);
            CHECK_GT(lane_sequence.lanesegment.size(), 0);
            CHECK_GT(lane_sequence.lanesegment.at(0).lanepoint.size(), 0);

            // Get obstacle info.
            const Feature &feature = obstacle.latest_feature();
            double theta = feature.velocityheading;
            double v = feature.speed;
            Point3D position = feature.position;
            int lane_seg_start_idx = lane_sequence.adclanesegmentidx;
            size_t lane_point_start_idx =
                lane_sequence.lanesegment.at(lane_seg_start_idx).adclanepointidx;
            if (lane_point_start_idx >=
                lane_sequence.lanesegment.at(lane_seg_start_idx).lanepoint.size())
            {
                lane_point_start_idx =
                    lane_sequence.lanesegment.at(lane_seg_start_idx).lanepoint.size() - 1;
            }
            const auto &start_lane_point =
                lane_sequence.lanesegment.at(lane_seg_start_idx)
                    .lanepoint.at(lane_point_start_idx);

            // Get lane info.
            double pos_delta_x = position.x - start_lane_point.position.x;
            double pos_delta_y = position.y - start_lane_point.position.y;
            double lane_heading_x = std::cos(start_lane_point.heading);
            double lane_heading_y = std::sin(start_lane_point.heading);

            // Check if obstacle is to the left(+) or right(-) of the lane.
            double cross_prod =
                lane_heading_x * pos_delta_y - lane_heading_y * pos_delta_x;
            double shift = std::hypot(pos_delta_x, pos_delta_y);

            // Set the initial conditions for solving diff. eqn.
            double l0 = (cross_prod > 0) ? shift : -shift;
            double dl0 = v * std::sin(theta - start_lane_point.heading);
            double l1 = 0.0;
            double dl1 = 0.0;

            // Solve for the coefficients.
            coefficients->operator[](0) = l0;
            coefficients->operator[](1) = dl0;
            double p = time_to_end_state;
            double p2 = p * p;
            double p3 = p2 * p;
            double tmp_var1 = (l1 - dl0) * p;
            double tmp_var2 = dl1 - l0 - dl0 * p;
            coefficients->operator[](2) = (3.0 * tmp_var2 - tmp_var1) / p2;
            coefficients->operator[](3) = (tmp_var1 - 2.0 * tmp_var2) / p3;

            return true;
        }

    } // namespace prediction
} // namespace apollo
