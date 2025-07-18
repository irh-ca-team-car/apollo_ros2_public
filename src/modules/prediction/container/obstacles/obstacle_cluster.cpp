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

#include "modules/prediction/container/obstacles/obstacle_clusters.h"

#include <algorithm>
#include <limits>

#include "modules/prediction/common/road_graph.h"

namespace apollo
{
    namespace prediction
    {

        using ::apollo::hdmap::LaneInfo;

        LaneGraph ObstacleClusters::GetLaneGraph(
            const double start_s, const double length, const bool consider_lane_split,
            std::shared_ptr<const LaneInfo> lane_info_ptr)
        {
            std::string lane_id = lane_info_ptr->id().id;
            RoadGraph road_graph(start_s, length, consider_lane_split, lane_info_ptr);
            LaneGraph lane_graph;
            road_graph.BuildLaneGraph(&lane_graph);
            return lane_graph;
        }

        LaneGraph ObstacleClusters::GetLaneGraphWithoutMemorizing(
            const double start_s, const double length, bool is_on_lane,
            std::shared_ptr<const LaneInfo> lane_info_ptr)
        {
            (void)is_on_lane;
            RoadGraph road_graph(start_s, length, true, lane_info_ptr);
            LaneGraph lane_graph;
            road_graph.BuildLaneGraphBidirection(&lane_graph);
            return lane_graph;
        }

        void ObstacleClusters::AddObstacle(const int obstacle_id,
                                           const std::string &lane_id,
                                           const double lane_s, const double lane_l)
        {
            LaneObstacle lane_obstacle;
            lane_obstacle.set__obstacleid(obstacle_id);
            lane_obstacle.set__laneid(lane_id);
            lane_obstacle.set__lanes(lane_s);
            lane_obstacle.set__lanel(lane_l);
            lane_obstacles_[lane_id].push_back(std::move(lane_obstacle));
        }

        void ObstacleClusters::SortObstacles()
        {
            for (auto iter = lane_obstacles_.begin(); iter != lane_obstacles_.end();
                 ++iter)
            {
                std::sort(iter->second.begin(), iter->second.end(),
                          [](const LaneObstacle &obs0, const LaneObstacle &obs1) -> bool {
                              return obs0.lanes < obs1.lanes;
                          });
            }
        }

        bool ObstacleClusters::ForwardNearbyObstacle(
            const LaneSequence &lane_sequence, const int obstacle_id,
            const double obstacle_s, const double obstacle_l,
            NearbyObstacle *const nearby_obstacle_ptr)
        {
            double accumulated_s = 0.0;
            for (const LaneSegment &lane_segment : lane_sequence.lanesegment)
            {
                std::string lane_id = lane_segment.laneid;
                double lane_length = lane_segment.totallength;
                if (lane_obstacles_.find(lane_id) == lane_obstacles_.end() ||
                    lane_obstacles_[lane_id].empty())
                {
                    accumulated_s += lane_length;
                    continue;
                }
                for (const LaneObstacle &lane_obstacle : lane_obstacles_[lane_id])
                {
                    if (lane_obstacle.obstacleid == obstacle_id)
                    {
                        continue;
                    }
                    double relative_s = accumulated_s + lane_obstacle.lanes - obstacle_s;
                    double relative_l = lane_obstacle.lanel - obstacle_l;
                    if (relative_s > 0.0)
                    {
                        nearby_obstacle_ptr->set__id(lane_obstacle.obstacleid);
                        nearby_obstacle_ptr->set__s(relative_s);
                        nearby_obstacle_ptr->set__l(relative_l);
                        return true;
                    }
                }
            }
            return false;
        }

        bool ObstacleClusters::BackwardNearbyObstacle(
            const LaneSequence &lane_sequence, const int obstacle_id,
            const double obstacle_s, const double obstacle_l,
            NearbyObstacle *const nearby_obstacle_ptr)
        {
            if (lane_sequence.lanesegment.empty())
            {
                AERROR << "Empty lane sequence found.";
                return false;
            }
            const LaneSegment &lane_segment = lane_sequence.lanesegment.at(0);
            std::string lane_id = lane_segment.laneid;

            // Search current lane
            if (lane_obstacles_.find(lane_id) != lane_obstacles_.end() &&
                !lane_obstacles_[lane_id].empty())
            {
                for (int i = static_cast<int>(lane_obstacles_[lane_id].size()) - 1; i >= 0;
                     --i)
                {
                    const LaneObstacle &lane_obstacle = lane_obstacles_[lane_id][i];
                    if (lane_obstacle.obstacleid == obstacle_id)
                    {
                        continue;
                    }
                    double relative_s = lane_obstacle.lanes - obstacle_s;
                    double relative_l = lane_obstacle.lanel - obstacle_l;
                    if (relative_s < 0.0)
                    {
                        nearby_obstacle_ptr->set__id(lane_obstacle.obstacleid);
                        nearby_obstacle_ptr->set__s(relative_s);
                        nearby_obstacle_ptr->set__l(relative_l);
                        return true;
                    }
                }
            }

            // Search backward lanes
            std::shared_ptr<const LaneInfo> lane_info_ptr =
                PredictionMap::LaneById(lane_id);
            bool found_one_behind = false;
            double relative_s = -std::numeric_limits<double>::infinity();
            double relative_l = 0.0;
            for (const auto &predecessor_lane_id :
                 lane_info_ptr->lane().predecessorid)
            {
                std::string lane_id = predecessor_lane_id.id;
                if (lane_obstacles_.find(lane_id) == lane_obstacles_.end() ||
                    lane_obstacles_[lane_id].empty())
                {
                    continue;
                }
                std::shared_ptr<const LaneInfo> pred_lane_info_ptr =
                    PredictionMap::LaneById(predecessor_lane_id.id);
                const LaneObstacle &backward_obs = lane_obstacles_[lane_id].back();
                double delta_s = backward_obs.lanes -
                                 (obstacle_s + pred_lane_info_ptr->total_length());
                found_one_behind = true;
                if (delta_s > relative_s)
                {
                    relative_s = delta_s;
                    relative_l = backward_obs.lanel - obstacle_l;
                    nearby_obstacle_ptr->set__id(backward_obs.obstacleid);
                    nearby_obstacle_ptr->set__s(relative_s);
                    nearby_obstacle_ptr->set__l(relative_l);
                }
            }

            return found_one_behind;
        }

        StopSign ObstacleClusters::QueryStopSignByLaneId(const std::string &lane_id)
        {
            StopSign stop_sign;
            // Find the stop_sign by lane_id in the hashtable
            if (lane_id_stop_sign_map_.find(lane_id) != lane_id_stop_sign_map_.end())
            {
                return lane_id_stop_sign_map_[lane_id];
            }
            std::shared_ptr<const LaneInfo> lane_info_ptr =
                PredictionMap::LaneById(lane_id);
            CHECK_NOTNULL(lane_info_ptr);
            for (const auto &overlap_id : lane_info_ptr->lane().overlapid)
            {
                auto overlap_info_ptr = PredictionMap::OverlapById(overlap_id.id);
                if (overlap_info_ptr == nullptr)
                {
                    continue;
                }
                for (const auto &object : overlap_info_ptr->overlap().object)
                {
                    // find the overlap with stop_sign
                    if (object.overlapinfo.stopsignoverlapinfo != 0)
                    {
                        for (const auto &obj : overlap_info_ptr->overlap().object)
                        {
                            // find the obj of in the overlap
                            if (obj.overlapinfo.laneoverlapinfo != apollo_msgs::msg::ApollohdmapLaneOverlapInfo())
                            {
                                if (
                                    stop_sign.lanes > obj.overlapinfo.laneoverlapinfo.starts)
                                {
                                    stop_sign.set__stopsignid(object.id.id);
                                    stop_sign.set__laneid(lane_id);
                                    stop_sign.set__lanes(obj.overlapinfo.laneoverlapinfo.starts);
                                    lane_id_stop_sign_map_[lane_id] = stop_sign;
                                }
                            }
                        }
                    }
                }
            }
            return lane_id_stop_sign_map_[lane_id];
        }

    } // namespace prediction
} // namespace apollo
