/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

#include "modules/prediction/evaluator/vehicle/cost_evaluator.h"
#include "modules/prediction/common/prediction_util.h"

namespace apollo
{
    namespace prediction
    {

        CostEvaluator::CostEvaluator()
        {
            evaluator_type_ = ObstacleConf::COST_EVALUATOR;
        }

        bool CostEvaluator::Evaluate(Obstacle *obstacle_ptr,
                                     ObstaclesContainer *obstacles_container)
        {
            (void)obstacles_container;
            CHECK_NOTNULL(obstacle_ptr);

            obstacle_ptr->SetEvaluatorType(evaluator_type_);

            int id = obstacle_ptr->id();
            if (obstacle_ptr->latest_feature() == Feature())
            {
                AERROR << "Obstacle [" << id << "] has no latest feature.";
                return false;
            }

            Feature *latest_feature_ptr = obstacle_ptr->mutable_latest_feature();
            CHECK_NOTNULL(latest_feature_ptr);
            if ((latest_feature_ptr->lane == Lane()) ||
                (latest_feature_ptr->lane.lanegraph ==LaneGraph()))
            {
                ADEBUG << "Obstacle [" << id << "] has no lane graph.";
                return false;
            }

            double obstacle_length;
            //if (latest_feature_ptr->has_length())
            {
                obstacle_length = latest_feature_ptr->length;
            }
            (void)obstacle_length;
            double obstacle_width;
            //if (latest_feature_ptr->has_width())
            {
                obstacle_width = latest_feature_ptr->width;
            }
            (void)obstacle_width;

            LaneGraph *lane_graph_ptr =
                &latest_feature_ptr->lane.lanegraph;
            CHECK_NOTNULL(lane_graph_ptr);
            if (lane_graph_ptr->lanesequence.empty())
            {
                AERROR << "Obstacle [" << id << "] has no lane sequences.";
                return false;
            }

            for (size_t i = 0; i < lane_graph_ptr->lanesequence.size(); ++i)
            {
                auto &lane_sequence_ptr = lane_graph_ptr->lanesequence.at(i);
                //CHECK_NOTNULL(lane_sequence_ptr);
                double probability =
                    ComputeProbability(obstacle_length, obstacle_width, lane_sequence_ptr);
                lane_sequence_ptr.set__probability(probability);
            }
            return true;
        }

        double CostEvaluator::ComputeProbability(const double obstacle_length,
                                                 const double obstacle_width,
                                                 const apollo_msgs::msg::ApollopredictionLaneSequence &lane_sequence)
        {
            double front_lateral_distance_cost =
                FrontLateralDistanceCost(obstacle_length, obstacle_width, lane_sequence);
            return apollo::common::math::Sigmoid(front_lateral_distance_cost);
        }

        double CostEvaluator::FrontLateralDistanceCost(
            const double obstacle_length, const double obstacle_width,
            const apollo_msgs::msg::ApollopredictionLaneSequence &lane_sequence)
        {
            (void)obstacle_width;
            if (lane_sequence.lanesegment.empty() ||
                lane_sequence.lanesegment.at(0).lanepoint.empty())
            {
                AWARN << "Empty lane sequence.";
                return 0.0;
            }
            const auto &lane_point = lane_sequence.lanesegment.at(0).lanepoint.at(0);
            double lane_l = -lane_point.relativel;
            double distance = std::abs(lane_l - obstacle_length / 2.0 *
                                                    std::sin(lane_point.anglediff));
            double half_lane_width = lane_point.width / 2.0;
            return half_lane_width - distance;
        }

    } // namespace prediction
} // namespace apollo
