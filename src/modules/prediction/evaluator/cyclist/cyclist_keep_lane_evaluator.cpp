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

#include "modules/prediction/evaluator/cyclist/cyclist_keep_lane_evaluator.h"

namespace apollo
{
    namespace prediction
    {

        CyclistKeepLaneEvaluator::CyclistKeepLaneEvaluator()
        {
            evaluator_type_ = ObstacleConf::CYCLIST_KEEP_LANE_EVALUATOR;
        }

        bool CyclistKeepLaneEvaluator::Evaluate(
            Obstacle *obstacle_ptr, ObstaclesContainer *obstacles_container)
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
                (latest_feature_ptr->lane.lanegraph== LaneGraph()) ||
                (latest_feature_ptr->lane.lanefeature==LaneFeature()))
            {
                ADEBUG << "Obstacle [" << id << "] has no lane graph.";
                return false;
            }

            LaneGraph *lane_graph_ptr =
                &latest_feature_ptr->lane.lanegraph;
            CHECK_NOTNULL(lane_graph_ptr);
            if (lane_graph_ptr->lanesequence.empty())
            {
                AERROR << "Obstacle [" << id << "] has no lane sequences.";
                return false;
            }

            std::string curr_lane_id =
                latest_feature_ptr->lane.lanefeature.laneid;

            for (auto &lane_sequence : lane_graph_ptr->lanesequence)
            {
                const double probability = ComputeProbability(curr_lane_id, lane_sequence);
                lane_sequence.set__probability(probability);
            }
            return true;
        }

        double CyclistKeepLaneEvaluator::ComputeProbability(
            const std::string &curr_lane_id, const apollo_msgs::msg::ApollopredictionLaneSequence &lane_sequence)
        {
            if (lane_sequence.lanesegment.empty())
            {
                AWARN << "Empty lane sequence.";
                return 0.0;
            }
            std::string lane_seq_first_id = lane_sequence.lanesegment.at(0).laneid;
            if (curr_lane_id == lane_seq_first_id)
            {
                return 1.0;
            }
            return 0.0;
        }

    } // namespace prediction
} // namespace apollo
