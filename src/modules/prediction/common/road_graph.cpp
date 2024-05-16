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

#include "modules/prediction/common/road_graph.h"

#include <algorithm>
#include <set>
#include <utility>

#include "modules/prediction/common/prediction_constants.h"
#include "modules/prediction/common/prediction_gflags.h"
#include "modules/prediction/common/prediction_system_gflags.h"

namespace apollo {
namespace prediction {
namespace {

using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::hdmap::Lane::LaneTurn;
using apollo::hdmap::LaneInfo;
using apollo_msgs::msg::ApollohdmapLane;

// Custom helper functions for sorting purpose.
bool HeadingIsAtLeft(const std::vector<double>& heading1,
                     const std::vector<double>& heading2, const size_t idx) {
  if (idx >= heading1.size() || idx >= heading2.size()) {
    return true;
  }
  const double angle =
      apollo::common::math::NormalizeAngle(heading1[idx] - heading2[idx]);
  if (angle > 0.0) {
    return true;
  } else if (angle < 0.0) {
    return false;
  }
  return HeadingIsAtLeft(heading1, heading2, idx + 1);
}

int ConvertTurnTypeToDegree(const ApollohdmapLane &lane)
{
  // Sanity checks.
  if (lane.turn ==0) {
    return 0;
  }

  // Assign a number to measure how much it is bent to the left.
  switch (lane.turn) {
  case LaneTurn::NO_TURN:
    return 0;
  case LaneTurn::LEFT_TURN:
    return 1;
  case LaneTurn::U_TURN:
    return 2;
  default:
    break;
  }

  return -1;
}

bool IsAtLeft(std::shared_ptr<const LaneInfo> lane1,
              std::shared_ptr<const LaneInfo> lane2) {
  if (lane1->lane().turn != 0 && lane2->lane().turn != 0 &&
      lane1->lane().turn != lane2->lane().turn) {
    int degree_to_left_1 = ConvertTurnTypeToDegree(lane1->lane());
    int degree_to_left_2 = ConvertTurnTypeToDegree(lane2->lane());
    return degree_to_left_1 > degree_to_left_2;
  }
  return HeadingIsAtLeft(lane1->headings(), lane2->headings(), 0);
}

}  // namespace

RoadGraph::RoadGraph(const double start_s, const double length,
                     const bool consider_divide,
                     std::shared_ptr<const LaneInfo> lane_info_ptr)
    : start_s_(start_s),
      length_(length),
      consider_divide_(consider_divide),
      lane_info_ptr_(lane_info_ptr) {}

Status RoadGraph::BuildLaneGraph(LaneGraph* const lane_graph_ptr) {
  // Sanity checks.
  if (length_ < 0.0 || lane_info_ptr_ == nullptr) {
    const auto error_msg = absl::StrCat(
        "Invalid road graph settings. Road graph length = ", length_);
    AERROR << error_msg;
    return Status(ErrorCode::PREDICTION_ERROR, error_msg);
  }
  if (lane_graph_ptr == nullptr) {
    const auto error_msg = "Invalid input lane graph.";
    AERROR << error_msg;
    return Status(ErrorCode::PREDICTION_ERROR, error_msg);
  }

  // Run the recursive function to perform DFS.
  std::list<LaneSegment> lane_segments;
  double accumulated_s = 0.0;
  ConstructLaneSequence(accumulated_s, start_s_, lane_info_ptr_,
                        FLAGS_road_graph_max_search_horizon, consider_divide_,
                        &lane_segments, lane_graph_ptr);

  return Status::OK();
}

Status RoadGraph::BuildLaneGraphBidirection(LaneGraph* const lane_graph_ptr) {
  // Sanity checks.
  if (length_ < 0.0 || lane_info_ptr_ == nullptr) {
    const auto error_msg = absl::StrCat(
        "Invalid road graph settings. Road graph length = ", length_);
    AERROR << error_msg;
    return Status(ErrorCode::PREDICTION_ERROR, error_msg);
  }
  if (lane_graph_ptr == nullptr) {
    const auto error_msg = "Invalid input lane graph.";
    AERROR << error_msg;
    return Status(ErrorCode::PREDICTION_ERROR, error_msg);
  }

  // Run the recursive function to perform DFS.
  std::list<LaneSegment> lane_segments;
  LaneGraph lane_graph_successor;
  ConstructLaneSequence(true, 0.0, start_s_, lane_info_ptr_,
                        FLAGS_road_graph_max_search_horizon, consider_divide_,
                        &lane_segments, &lane_graph_successor);
  lane_segments.clear();
  LaneGraph lane_graph_predecessor;
  length_ = length_ / 2.0;
  ConstructLaneSequence(false, 0.0, start_s_, lane_info_ptr_,
                        FLAGS_road_graph_max_search_horizon, consider_divide_,
                        &lane_segments, &lane_graph_predecessor);
  *lane_graph_ptr =
      CombineLaneGraphs(lane_graph_predecessor, lane_graph_successor);

  return Status::OK();
}

LaneGraph RoadGraph::CombineLaneGraphs(const LaneGraph& lane_graph_predecessor,
                                       const LaneGraph& lane_graph_successor) {
  LaneGraph final_lane_graph;
  for (const auto& lane_sequence_pre : lane_graph_predecessor.lanesequence) {
    const auto& ending_lane_segment = lane_sequence_pre.lanesegment.at(
        lane_sequence_pre.lanesegment.size() - 1);
    for (const auto& lane_sequence_suc : lane_graph_successor.lanesequence) {
      if (lane_sequence_suc.lanesegment.at(0).laneid ==
          ending_lane_segment.laneid) {
        auto& lane_sequence = final_lane_graph.lanesequence.emplace_back();
        for (const auto& it : lane_sequence_pre.lanesegment) {
          lane_sequence.lanesegment.push_back(it);
        }
        lane_sequence.lanesegment.at(lane_sequence.lanesegment.size() - 1).set__ends(lane_sequence_suc.lanesegment.at(0).ends);
        lane_sequence.lanesegment.at(lane_sequence.lanesegment.size() - 1).set__adcs(lane_sequence_suc.lanesegment.at(0).starts);
        lane_sequence.set__adclanesegmentidx( lane_sequence.lanesegment.size() - 1);
        for (size_t i = 1; i < lane_sequence_suc.lanesegment.size(); ++i) {
          lane_sequence.lanesegment.push_back(lane_sequence_suc.lanesegment.at(i));
        }
      }
    }
  }

  return final_lane_graph;
}

bool RoadGraph::IsOnLaneGraph(std::shared_ptr<const LaneInfo> lane_info_ptr,
                              const LaneGraph& lane_graph) {
  if (lane_graph == LaneGraph()) {
    return false;
  }

  for (const auto& lane_sequence : lane_graph.lanesequence) {
    for (const auto& lane_segment : lane_sequence.lanesegment) {
      if (lane_segment.laneid != std::string() &&
          lane_segment.laneid == lane_info_ptr->id().id) {
        return true;
      }
    }
  }
  return false;
}

void RoadGraph::ConstructLaneSequence(
    const double accumulated_s, const double curr_lane_seg_s,
    std::shared_ptr<const LaneInfo> lane_info_ptr,
    const int graph_search_horizon, const bool consider_lane_split,
    std::list<LaneSegment>* const lane_segments,
    LaneGraph* const lane_graph_ptr) const {
  ConstructLaneSequence(true, accumulated_s, curr_lane_seg_s, lane_info_ptr,
                        graph_search_horizon, consider_lane_split,
                        lane_segments, lane_graph_ptr);
}

void RoadGraph::ConstructLaneSequence(
    const bool search_forward_direction, const double accumulated_s,
    const double curr_lane_seg_s, std::shared_ptr<const LaneInfo> lane_info_ptr,
    const int graph_search_horizon, const bool consider_lane_split,
    std::list<LaneSegment>* const lane_segments,
    LaneGraph* const lane_graph_ptr) const {
  // Sanity checks.
  if (lane_info_ptr == nullptr) {
    AERROR << "Invalid lane.";
    return;
  }
  if (graph_search_horizon < 0) {
    AERROR << "The lane search has already reached the limits";
    AERROR << "Possible map error found!";
    return;
  }

  // Create a new lane_segment based on the current lane_info_ptr.
  double curr_s =
      curr_lane_seg_s >= 0.0 ? curr_lane_seg_s : lane_info_ptr->total_length();
  LaneSegment lane_segment;
  lane_segment.set__adcs(curr_s);
  lane_segment.set__laneid(lane_info_ptr->id().id);
  lane_segment.set__laneturntype(
      PredictionMap::LaneTurnType(lane_info_ptr->id().id));
  lane_segment.set__totallength(lane_info_ptr->total_length());
  if (search_forward_direction) {
    lane_segment.set__starts(curr_s);
    lane_segment.set__ends(std::fmin(curr_s + length_ - accumulated_s,
                                      lane_info_ptr->total_length()));
  } else {
    lane_segment.set__starts(
        std::fmax(0.0, curr_s - (length_ - accumulated_s)));
    lane_segment.set__ends(curr_s);
  }
  if (search_forward_direction) {
    lane_segments->push_back(std::move(lane_segment));
  } else {
    lane_segments->push_front(std::move(lane_segment));
  }

  // End condition: if search reached the maximum search distance,
  // or if there is no more successor lane_segment.
  if (search_forward_direction) {
    if (lane_segments->back().ends < lane_info_ptr->total_length() ||
        lane_info_ptr->lane().successorid.empty()) {
      auto& sequence = lane_graph_ptr->lanesequence.emplace_back();
      for (const auto& it : *lane_segments) {
        sequence.lanesegment.push_back(it);
      }
      lane_segments->pop_back();
      return;
    }
  } else {
    if (lane_segments->front().starts > 0.0 ||
        lane_info_ptr->lane().predecessorid.empty()) {
      auto& sequence = lane_graph_ptr->lanesequence.emplace_back();
      for (const auto& it : *lane_segments) {
        sequence.lanesegment.push_back(it);
      }
      lane_segments->pop_front();
      return;
    }
  }

  // Otherwise, continue searching for subsequent lane_segments.
  double new_accumulated_s = 0.0;
  double new_lane_seg_s = 0.0;
  std::vector<std::shared_ptr<const hdmap::LaneInfo>> candidate_lanes;
  std::set<std::string> set_lane_ids;
  if (search_forward_direction) {
    new_accumulated_s = accumulated_s + lane_info_ptr->total_length() - curr_s;
    // Reundancy removal.
    for (const auto& successor_lane_id : lane_info_ptr->lane().successorid) {
      set_lane_ids.insert(successor_lane_id.id);
    }
    for (const auto& unique_id : set_lane_ids) {
      candidate_lanes.push_back(PredictionMap::LaneById(unique_id));
    }
    // Sort the successor lane_segments from left to right.
    std::sort(candidate_lanes.begin(), candidate_lanes.end(), IsAtLeft);
    // Based on other conditions, select what successor lanes should be used.
    if (!consider_lane_split) {
      candidate_lanes = {
          PredictionMap::LaneWithSmallestAverageCurvature(candidate_lanes)};
    }
  } else {
    new_accumulated_s = accumulated_s + curr_s;
    new_lane_seg_s = -0.1;
    // Redundancy removal.
    for (const auto& predecessor_lane_id :
         lane_info_ptr->lane().predecessorid) {
      set_lane_ids.insert(predecessor_lane_id.id);
    }
    for (const auto& unique_id : set_lane_ids) {
      candidate_lanes.push_back(PredictionMap::LaneById(unique_id));
    }
  }
  bool consider_further_lane_split =
      !search_forward_direction ||
      (FLAGS_prediction_offline_mode ==
       PredictionConstants::kDumpFeatureProto) ||
      (FLAGS_prediction_offline_mode ==
       PredictionConstants::kDumpDataForLearning) ||
      (consider_lane_split && candidate_lanes.size() == 1);
  // Recursively expand lane-sequence.
  for (const auto& candidate_lane : candidate_lanes) {
    ConstructLaneSequence(search_forward_direction, new_accumulated_s,
                          new_lane_seg_s, candidate_lane,
                          graph_search_horizon - 1, consider_further_lane_split,
                          lane_segments, lane_graph_ptr);
  }
  if (search_forward_direction) {
    lane_segments->pop_back();
  } else {
    lane_segments->pop_front();
  }
}

}  // namespace prediction
}  // namespace apollo
