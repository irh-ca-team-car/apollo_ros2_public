/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
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

#include "modules/prediction/predictor/extrapolation/extrapolation_predictor.h"

#include "modules/common/math/vec2d.h"
#include "modules/prediction/common/prediction_gflags.h"
#include "modules/prediction/common/prediction_map.h"
#include "modules/prediction/proto/lane_graph.pb.h"

namespace apollo
{
    namespace prediction
    {

        using apollo::common::PathPoint;
        using apollo::common::TrajectoryPoint;

        ExtrapolationPredictor::ExtrapolationPredictor()
        {
            predictor_type_ = ObstacleConf::EXTRAPOLATION_PREDICTOR;
        }

        bool ExtrapolationPredictor::Predict(
            const ADCTrajectoryContainer *adc_trajectory_container, Obstacle *obstacle,
            ObstaclesContainer *obstacles_container)
        {
            (void)adc_trajectory_container;
            (void)obstacles_container;
            Clear();

            CHECK_NOTNULL(obstacle);
            CHECK_GT(obstacle->history_size(), 0U);

            obstacle->SetPredictorType(predictor_type_);

            Feature *feature_ptr = obstacle->mutable_latest_feature();

            if (feature_ptr->lane.lanegraph == LaneGraph())
            {
                AERROR << "Obstacle [" << obstacle->id() << "] has no lane graph.";
                return false;
            }
            if (feature_ptr->predictedtrajectory.empty())
            {
                AERROR << "Obstacle [" << obstacle->id()
                       << "] has no short-term trajectories.";
                return false;
            }
            auto *cluster_ptr = obstacles_container->GetClustersPtr();
            for (size_t i = 0; i < feature_ptr->predictedtrajectory.size(); ++i)
            {
                Trajectory *trajectory_ptr = &feature_ptr->predictedtrajectory.at(i);
                PostProcess(trajectory_ptr, cluster_ptr);
            }
            return true;
        }

        void ExtrapolationPredictor::PostProcess(Trajectory *trajectory_ptr,
                                                 ObstacleClusters *clusters_ptr)
        {
            // TODO(kechxu) handle corner cases
            static constexpr int kNumTailPoint = 5;
            ExtrapolationPredictor::LaneSearchResult lane_search_result =
                SearchExtrapolationLane(*trajectory_ptr, kNumTailPoint);
            double extraplation_speed =
                ComputeExtraplationSpeed(kNumTailPoint, *trajectory_ptr);
            if (lane_search_result.found)
            {
                ExtrapolateByLane(lane_search_result, extraplation_speed, trajectory_ptr,
                                  clusters_ptr);
            }
            else
            {
                ExtrapolateByFreeMove(kNumTailPoint, extraplation_speed, trajectory_ptr);
            }
        }

        ExtrapolationPredictor::LaneSearchResult
        ExtrapolationPredictor::SearchExtrapolationLane(const Trajectory &trajectory,
                                                        const int num_tail_point)
        {
            static constexpr double radius = 1.0;
            static constexpr double angle_diff_threshold = M_PI / 3.0;
            int num_trajectory_point = trajectory.trajectorypoint.size();

            LaneSearchResult lane_search_result;
            for (int i = num_trajectory_point - 1;
                 i >= num_trajectory_point - num_tail_point; --i)
            {
                const TrajectoryPoint &trajectory_point = trajectory.trajectorypoint.at(i);
                const PathPoint &path_point = trajectory_point.pathpoint;
                apollo::common::PointENU point_enu;
                point_enu.set__x(path_point.x);
                point_enu.set__y(path_point.y);
                double heading = path_point.theta;
                auto lane_info_ptr = PredictionMap::GetMostLikelyCurrentLane(
                    point_enu, radius, heading, angle_diff_threshold);
                if (lane_info_ptr != nullptr)
                {
                    lane_search_result.found = true;
                    lane_search_result.lane_id = lane_info_ptr->lane().id.id;
                    lane_search_result.point_index = i;
                    break;
                }
            }
            return lane_search_result;
        }

        void ExtrapolationPredictor::ExtrapolateByLane(
            const LaneSearchResult &lane_search_result, const double extraplation_speed,
            Trajectory *trajectory_ptr, ObstacleClusters *clusters_ptr)
        {
            std::string start_lane_id = lane_search_result.lane_id;
            size_t point_index = lane_search_result.point_index;
            while (trajectory_ptr->trajectorypoint.size() > point_index + 1)
            {
                trajectory_ptr->trajectorypoint.pop_back();
            }
            auto lane_info_ptr = PredictionMap::LaneById(start_lane_id);
            int num_trajectory_point = trajectory_ptr->trajectorypoint.size();
            const TrajectoryPoint &last_point =
                trajectory_ptr->trajectorypoint.at(num_trajectory_point - 1);

            Eigen::Vector2d position(last_point.pathpoint.x,
                                     last_point.pathpoint.y);
            double lane_s = 0.0;
            double lane_l = 0.0;
            bool projected =
                PredictionMap::GetProjection(position, lane_info_ptr, &lane_s, &lane_l);
            if (!projected)
            {
                AERROR << "Position (" << position.x() << ", " << position.y() << ") "
                       << "cannot be projected onto lane [" << start_lane_id << "]";
                return;
            }

            double last_relative_time = last_point.relativetime;
            double time_range =
                FLAGS_prediction_trajectory_time_length - last_relative_time;
            double time_resolution = FLAGS_prediction_trajectory_time_resolution;
            double length = extraplation_speed * time_range;

            LaneGraph lane_graph =
                clusters_ptr->GetLaneGraph(lane_s, length, false, lane_info_ptr);
            CHECK_EQ(lane_graph.lanesequence.size(), 1);
            const auto &lane_sequence = lane_graph.lanesequence.at(0);
            size_t lane_segment_index = 0;
            std::string lane_id =
                lane_sequence.lanesegment.at(lane_segment_index).laneid;

            int num_point_remained = static_cast<int>(time_range / time_resolution);
            for (int i = 1; i <= num_point_remained; ++i)
            {
                double relative_time =
                    last_relative_time + static_cast<double>(i) * time_resolution;
                Eigen::Vector2d point;
                double theta = M_PI;
                if (!PredictionMap::SmoothPointFromLane(lane_id, lane_s, lane_l, &point,
                                                        &theta))
                {
                    AERROR << "Unable to get smooth point from lane [" << lane_id
                           << "] with s [" << lane_s << "] and l [" << lane_l << "]";
                    break;
                }
                TrajectoryPoint *trajectory_point = &trajectory_ptr->trajectorypoint.emplace_back();
                PathPoint *path_point = &trajectory_point->pathpoint;
                path_point->set__x(point.x());
                path_point->set__y(point.y());
                path_point->set__z(0.0);
                path_point->set__theta(theta);
                path_point->set__laneid(lane_id);
                trajectory_point->set__v(extraplation_speed);
                trajectory_point->set__a(0.0);
                trajectory_point->set__relativetime(relative_time);

                lane_s += extraplation_speed * time_resolution;
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

        void ExtrapolationPredictor::ExtrapolateByFreeMove(
            const int num_tail_point, const double extraplation_speed,
            Trajectory *trajectory_ptr)
        {
            (void)num_tail_point;
            int num_trajectory_point = trajectory_ptr->trajectorypoint.size();
            const TrajectoryPoint &last_point =
                trajectory_ptr->trajectorypoint.at(num_trajectory_point - 1);
            double theta = last_point.pathpoint.theta;
            double time_resolution = FLAGS_prediction_trajectory_time_resolution;
            double time_length = FLAGS_prediction_trajectory_time_length;
            double relative_time = last_point.relativetime + time_resolution;
            while (relative_time < time_length)
            {
                int prev_size = trajectory_ptr->trajectorypoint.size();
                const TrajectoryPoint &prev_point =
                    trajectory_ptr->trajectorypoint.at(prev_size - 1);
                TrajectoryPoint *curr_point = &trajectory_ptr->trajectorypoint.emplace_back();
                double dx = time_resolution * extraplation_speed * std::cos(theta);
                double dy = time_resolution * extraplation_speed * std::sin(theta);
                double curr_x = prev_point.pathpoint.x + dx;
                double curr_y = prev_point.pathpoint.y + dy;
                PathPoint *curr_path_point_ptr = &curr_point->pathpoint;
                curr_path_point_ptr->set__x(curr_x);
                curr_path_point_ptr->set__y(curr_y);
                curr_path_point_ptr->set__theta(theta);
                curr_point->set__v(extraplation_speed);
                curr_point->set__relativetime(relative_time);

                relative_time += time_resolution;
            }
        }

        double ExtrapolationPredictor::ComputeExtraplationSpeed(
            const int num_tail_point, const Trajectory &trajectory)
        {
            int num_trajectory_point = trajectory.trajectorypoint.size();
            CHECK_GT(num_trajectory_point, num_tail_point);
            CHECK_GT(num_tail_point, 0);
            double v_sum = 0.0;
            int mid_index = num_trajectory_point - num_tail_point;
            for (int i = mid_index; i < num_trajectory_point; ++i)
            {
                v_sum += trajectory.trajectorypoint.at(i).v;
            }
            return v_sum / static_cast<double>(num_tail_point);
        }

    } // namespace prediction
} // namespace apollo
