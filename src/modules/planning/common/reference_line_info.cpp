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

/**
 * @file
 **/

#include "modules/planning/common/reference_line_info.h"

#include <algorithm>

#include "absl/strings/str_cat.h"
#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/common/util/point_factory.h"
#include "modules/common/util/util.h"
#include "modules/map/hdmap/hdmap_common.h"
#include "modules/map/hdmap/hdmap_util.h"
#include "modules/planning/proto/planning_status.pb.h"
#include "modules/planning/proto/sl_boundary.pb.h"

namespace apollo {
namespace planning {

using apollo_msgs::msg::ApollocanbusChassis;
using apollo::common::TrajectoryPoint;
using apollo::common::VehicleConfigHelper;
using apollo::common::math::Box2d;
using apollo::common::math::Vec2d;
using apollo::common::util::PointFactory;

std::unordered_map<std::string, bool>
    ReferenceLineInfo::junction_right_of_way_map_;

ReferenceLineInfo::ReferenceLineInfo(const common::VehicleState& vehicle_state,
                                     const TrajectoryPoint& adc_planning_point,
                                     const ReferenceLine& reference_line,
                                     const hdmap::RouteSegments& segments)
    : vehicle_state_(vehicle_state),
      adc_planning_point_(adc_planning_point),
      reference_line_(reference_line),
      lanes_(segments) {}

bool ReferenceLineInfo::Init(const std::vector<const Obstacle*>& obstacles) {
  const auto& param = VehicleConfigHelper::GetConfig().vehicleparam;
  // stitching point
  const auto& path_point = adc_planning_point_.pathpoint;
  Vec2d position(path_point.x, path_point.y);
  Vec2d vec_to_center(
      (param.frontedgetocenter - param.backedgetocenter) / 2.0,
      (param.leftedgetocenter - param.rightedgetocenter) / 2.0);
  Vec2d center(position + vec_to_center.rotate(path_point.theta));
  Box2d box(center, path_point.theta, param.length, param.width);
  // realtime vehicle position
  Vec2d vehicle_position(vehicle_state_.x, vehicle_state_.y);
  Vec2d vehicle_center(vehicle_position +
                       vec_to_center.rotate(vehicle_state_.heading));
  Box2d vehicle_box(vehicle_center, vehicle_state_.heading, param.length,
                    param.width);

  if (!reference_line_.GetSLBoundary(box, &adc_sl_boundary_)) {
    AERROR << "Failed to get ADC boundary from box: " << box.DebugString();
    return false;
  }

  InitFirstOverlaps();

  if (adc_sl_boundary_.ends < 0 ||
      adc_sl_boundary_.starts > reference_line_.Length()) {
    AWARN << "Vehicle SL " << adc_sl_boundary_
          << " is not on reference line:[0, " << reference_line_.Length()
          << "]";
  }
  static constexpr double kOutOfReferenceLineL = 10.0;  // in meters
  if (adc_sl_boundary_.startl > kOutOfReferenceLineL ||
      adc_sl_boundary_.endl < -kOutOfReferenceLineL) {
    AERROR << "Ego vehicle is too far away from reference line.";
    return false;
  }
  is_on_reference_line_ = reference_line_.IsOnLane(adc_sl_boundary_);
  if (!AddObstacles(obstacles)) {
    AERROR << "Failed to add obstacles to reference line";
    return false;
  }

  const auto& map_path = reference_line_.map_path();
  for (const auto& speed_bump : map_path.speed_bump_overlaps()) {
    // -1 and + 1.0 are added to make sure it can be sampled.
    reference_line_.AddSpeedLimit(speed_bump.start_s - 1.0,
                                  speed_bump.end_s + 1.0,
                                  FLAGS_speed_bump_speed_limit);
  }

  SetCruiseSpeed(FLAGS_default_cruise_speed);

  // set lattice planning target speed limit;
  SetLatticeCruiseSpeed(FLAGS_default_cruise_speed);

  vehicle_signal_ = apollo_msgs::msg::ApollocommonVehicleSignal();

  return true;
}

const std::vector<PathData>& ReferenceLineInfo::GetCandidatePathData() const {
  return candidate_path_data_;
}

void ReferenceLineInfo::SetCandidatePathData(
    std::vector<PathData>&& candidate_path_data) {
  candidate_path_data_ = std::move(candidate_path_data);
}

const std::vector<PathBoundary>& ReferenceLineInfo::GetCandidatePathBoundaries()
    const {
  return candidate_path_boundaries_;
}

void ReferenceLineInfo::SetCandidatePathBoundaries(
    std::vector<PathBoundary>&& path_boundaries) {
  candidate_path_boundaries_ = std::move(path_boundaries);
}

double ReferenceLineInfo::GetCruiseSpeed() const {
  return cruise_speed_ > 0.0 ? cruise_speed_ : FLAGS_default_cruise_speed;
}

hdmap::LaneInfoConstPtr ReferenceLineInfo::LocateLaneInfo(
    const double s) const {
  std::vector<hdmap::LaneInfoConstPtr> lanes;
  reference_line_.GetLaneFromS(s, &lanes);
  if (lanes.empty()) {
    AWARN << "cannot get any lane using s";
    return nullptr;
  }

  return lanes.front();
}

bool ReferenceLineInfo::GetNeighborLaneInfo(
    const ReferenceLineInfo::LaneType lane_type, const double s,
    hdmap::Id* ptr_lane_id, double* ptr_lane_width) const {
  auto ptr_lane_info = LocateLaneInfo(s);
  if (ptr_lane_info == nullptr) {
    return false;
  }

  switch (lane_type) {
    case LaneType::LeftForward: {
      if (ptr_lane_info->lane().leftneighborforwardlaneid.empty()) {
        return false;
      }
      *ptr_lane_id = ptr_lane_info->lane().leftneighborforwardlaneid.at(0);
      break;
    }
    case LaneType::LeftReverse: {
      if (ptr_lane_info->lane().leftneighborreverselaneid.empty()) {
        return false;
      }
      *ptr_lane_id = ptr_lane_info->lane().leftneighborreverselaneid.at(0);
      break;
    }
    case LaneType::RightForward: {
      if (ptr_lane_info->lane().rightneighborforwardlaneid.empty()) {
        return false;
      }
      *ptr_lane_id = ptr_lane_info->lane().rightneighborforwardlaneid.at(0);
      break;
    }
    case LaneType::RightReverse: {
      if (ptr_lane_info->lane().rightneighborreverselaneid.empty()) {
        return false;
      }
      *ptr_lane_id = ptr_lane_info->lane().rightneighborreverselaneid.at(0);
      break;
    }
    default:
      ACHECK(false);
  }
  auto ptr_neighbor_lane =
      hdmap::HDMapUtil::BaseMapPtr()->GetLaneById(*ptr_lane_id);
  if (ptr_neighbor_lane == nullptr) {
    return false;
  }

  auto ref_point = reference_line_.GetReferencePoint(s);

  double neighbor_s = 0.0;
  double neighbor_l = 0.0;
  if (!ptr_neighbor_lane->GetProjection({ref_point.x(), ref_point.y()},
                                        &neighbor_s, &neighbor_l)) {
    return false;
  }

  *ptr_lane_width = ptr_neighbor_lane->GetWidth(neighbor_s);
  return true;
}

bool ReferenceLineInfo::GetFirstOverlap(
    const std::vector<hdmap::PathOverlap>& path_overlaps,
    hdmap::PathOverlap* path_overlap) {
  CHECK_NOTNULL(path_overlap);
  const double start_s = adc_sl_boundary_.ends;
  static constexpr double kMaxOverlapRange = 500.0;
  double overlap_min_s = kMaxOverlapRange;

  auto overlap_min_s_iter = path_overlaps.end();
  for (auto iter = path_overlaps.begin(); iter != path_overlaps.end(); ++iter) {
    if (iter->end_s < start_s) {
      continue;
    }
    if (overlap_min_s > iter->start_s) {
      overlap_min_s_iter = iter;
      overlap_min_s = iter->start_s;
    }
  }

  // Ensure that the path_overlaps is not empty.
  if (overlap_min_s_iter != path_overlaps.end()) {
    *path_overlap = *overlap_min_s_iter;
  }

  return overlap_min_s < kMaxOverlapRange;
}

void ReferenceLineInfo::InitFirstOverlaps() {
  const auto& map_path = reference_line_.map_path();
  // clear_zone
  hdmap::PathOverlap clear_area_overlap;
  if (GetFirstOverlap(map_path.clear_area_overlaps(), &clear_area_overlap)) {
    first_encounter_overlaps_.emplace_back(CLEAR_AREA, clear_area_overlap);
  }

  // crosswalk
  hdmap::PathOverlap crosswalk_overlap;
  if (GetFirstOverlap(map_path.crosswalk_overlaps(), &crosswalk_overlap)) {
    first_encounter_overlaps_.emplace_back(CROSSWALK, crosswalk_overlap);
  }

  // pnc_junction
  hdmap::PathOverlap pnc_junction_overlap;
  if (GetFirstOverlap(map_path.pnc_junction_overlaps(),
                      &pnc_junction_overlap)) {
    first_encounter_overlaps_.emplace_back(PNC_JUNCTION, pnc_junction_overlap);
  }

  // signal
  hdmap::PathOverlap signal_overlap;
  if (GetFirstOverlap(map_path.signal_overlaps(), &signal_overlap)) {
    first_encounter_overlaps_.emplace_back(SIGNAL, signal_overlap);
  }

  // stop_sign
  hdmap::PathOverlap stop_sign_overlap;
  if (GetFirstOverlap(map_path.stop_sign_overlaps(), &stop_sign_overlap)) {
    first_encounter_overlaps_.emplace_back(STOP_SIGN, stop_sign_overlap);
  }

  // yield_sign
  hdmap::PathOverlap yield_sign_overlap;
  if (GetFirstOverlap(map_path.yield_sign_overlaps(), &yield_sign_overlap)) {
    first_encounter_overlaps_.emplace_back(YIELD_SIGN, yield_sign_overlap);
  }

  // sort by start_s
  if (!first_encounter_overlaps_.empty()) {
    std::sort(first_encounter_overlaps_.begin(),
              first_encounter_overlaps_.end(),
              [](const std::pair<OverlapType, hdmap::PathOverlap>& a,
                 const std::pair<OverlapType, hdmap::PathOverlap>& b) {
                return a.second.start_s < b.second.start_s;
              });
  }
}

bool WithinOverlap(const hdmap::PathOverlap& overlap, double s) {
  static constexpr double kEpsilon = 1e-2;
  return overlap.start_s - kEpsilon <= s && s <= overlap.end_s + kEpsilon;
}

void ReferenceLineInfo::SetJunctionRightOfWay(const double junction_s,
                                              const bool is_protected) const {
  for (const auto& overlap : reference_line_.map_path().junction_overlaps()) {
    if (WithinOverlap(overlap, junction_s)) {
      junction_right_of_way_map_[overlap.object_id] = is_protected;
    }
  }
}

ADCTrajectory::RightOfWayStatus ReferenceLineInfo::GetRightOfWayStatus() const {
  for (const auto& overlap : reference_line_.map_path().junction_overlaps()) {
    if (overlap.end_s < adc_sl_boundary_.starts) {
      junction_right_of_way_map_.erase(overlap.object_id);
    } else if (WithinOverlap(overlap, adc_sl_boundary_.ends)) {
      auto is_protected = junction_right_of_way_map_[overlap.object_id];
      if (is_protected) {
        return ADCTrajectory::PROTECTED;
      }
    }
  }
  return ADCTrajectory::UNPROTECTED;
}

const hdmap::RouteSegments& ReferenceLineInfo::Lanes() const { return lanes_; }

std::list<hdmap::Id> ReferenceLineInfo::TargetLaneId() const {
  std::list<hdmap::Id> lane_ids;
  for (const auto& lane_seg : lanes_) {
    lane_ids.push_back(lane_seg.lane->id());
  }
  return lane_ids;
}

const SLBoundary& ReferenceLineInfo::AdcSlBoundary() const {
  return adc_sl_boundary_;
}

PathDecision* ReferenceLineInfo::path_decision() { return &path_decision_; }

const PathDecision& ReferenceLineInfo::path_decision() const {
  return path_decision_;
}

const ReferenceLine& ReferenceLineInfo::reference_line() const {
  return reference_line_;
}

ReferenceLine* ReferenceLineInfo::mutable_reference_line() {
  return &reference_line_;
}

void ReferenceLineInfo::SetTrajectory(const DiscretizedTrajectory& trajectory) {
  discretized_trajectory_ = trajectory;
}

bool ReferenceLineInfo::AddObstacleHelper(
    const std::shared_ptr<Obstacle>& obstacle) {
  return AddObstacle(obstacle.get()) != nullptr;
}

// AddObstacle is thread safe
Obstacle* ReferenceLineInfo::AddObstacle(const Obstacle* obstacle) {
  if (!obstacle) {
    AERROR << "The provided obstacle is empty";
    return nullptr;
  }
  auto* mutable_obstacle = path_decision_.AddObstacle(*obstacle);
  if (!mutable_obstacle) {
    AERROR << "failed to add obstacle " << obstacle->Id();
    return nullptr;
  }

  SLBoundary perception_sl;
  if (!reference_line_.GetSLBoundary(obstacle->PerceptionBoundingBox(),
                                     &perception_sl)) {
    AERROR << "Failed to get sl boundary for obstacle: " << obstacle->Id();
    return mutable_obstacle;
  }
  mutable_obstacle->SetPerceptionSlBoundary(perception_sl);
  mutable_obstacle->CheckLaneBlocking(reference_line_);
  if (mutable_obstacle->IsLaneBlocking()) {
    ADEBUG << "obstacle [" << obstacle->Id() << "] is lane blocking.";
  } else {
    ADEBUG << "obstacle [" << obstacle->Id() << "] is NOT lane blocking.";
  }

  if (IsIrrelevantObstacle(*mutable_obstacle)) {
    ApolloplanningObjectDecisionType ignore;
    path_decision_.AddLateralDecision("reference_line_filter", obstacle->Id(),
                                      ignore);
    path_decision_.AddLongitudinalDecision("reference_line_filter",
                                           obstacle->Id(), ignore);
    ADEBUG << "NO build reference line st boundary. id:" << obstacle->Id();
  } else {
    ADEBUG << "build reference line st boundary. id:" << obstacle->Id();
    mutable_obstacle->BuildReferenceLineStBoundary(reference_line_,
                                                   adc_sl_boundary_.starts);

    ADEBUG << "reference line st boundary: t["
           << mutable_obstacle->reference_line_st_boundary().min_t() << ", "
           << mutable_obstacle->reference_line_st_boundary().max_t() << "] s["
           << mutable_obstacle->reference_line_st_boundary().min_s() << ", "
           << mutable_obstacle->reference_line_st_boundary().max_s() << "]";
  }
  return mutable_obstacle;
}

bool ReferenceLineInfo::AddObstacles(
    const std::vector<const Obstacle*>& obstacles) {
  if (FLAGS_use_multi_thread_to_add_obstacles) {
    std::vector<std::future<Obstacle*>> results;
    for (const auto* obstacle : obstacles) {
      results.push_back(
          std::async(&ReferenceLineInfo::AddObstacle, this, obstacle));
    }
    for (auto& result : results) {
      if (!result.get()) {
        AERROR << "Fail to add obstacles.";
        return false;
      }
    }
  } else {
    for (const auto* obstacle : obstacles) {
      if (!AddObstacle(obstacle)) {
        AERROR << "Failed to add obstacle " << obstacle->Id();
        return false;
      }
    }
  }

  return true;
}

bool ReferenceLineInfo::IsIrrelevantObstacle(const Obstacle& obstacle) {
  if (obstacle.IsCautionLevelObstacle()) {
    return false;
  }
  // if adc is on the road, and obstacle behind adc, ignore
  const auto& obstacle_boundary = obstacle.PerceptionSLBoundary();
  if (obstacle_boundary.ends > reference_line_.Length()) {
    return true;
  }
  if (is_on_reference_line_ && !IsChangeLanePath() &&
      obstacle_boundary.ends < adc_sl_boundary_.ends &&
      (reference_line_.IsOnLane(obstacle_boundary) ||
       obstacle_boundary.ends < 0.0)) {  // if obstacle is far backward
    return true;
  }
  return false;
}

const DiscretizedTrajectory& ReferenceLineInfo::trajectory() const {
  return discretized_trajectory_;
}

void ReferenceLineInfo::SetLatticeStopPoint(const apollo_msgs::msg::ApolloplanningStopPoint& stop_point) {
  planning_target_.stoppoint = stop_point;
}

void ReferenceLineInfo::SetLatticeCruiseSpeed(double speed) {
  planning_target_.set__cruisespeed(speed);
}

bool ReferenceLineInfo::IsStartFrom(
    const ReferenceLineInfo& previous_reference_line_info) const {
  if (reference_line_.reference_points().empty()) {
    return false;
  }
  auto start_point = reference_line_.reference_points().front();
  const auto& prev_reference_line =
      previous_reference_line_info.reference_line();
  common::SLPoint sl_point;
  prev_reference_line.XYToSL(start_point, &sl_point);
  return previous_reference_line_info.reference_line_.IsOnLane(sl_point);
}

const PathData& ReferenceLineInfo::path_data() const { return path_data_; }

const PathData& ReferenceLineInfo::fallback_path_data() const {
  return fallback_path_data_;
}

const SpeedData& ReferenceLineInfo::speed_data() const { return speed_data_; }

PathData* ReferenceLineInfo::mutable_path_data() { return &path_data_; }

PathData* ReferenceLineInfo::mutable_fallback_path_data() {
  return &fallback_path_data_;
}

SpeedData* ReferenceLineInfo::mutable_speed_data() { return &speed_data_; }

const RSSInfo& ReferenceLineInfo::rss_info() const { return rss_info_; }

RSSInfo* ReferenceLineInfo::mutable_rss_info() { return &rss_info_; }

bool ReferenceLineInfo::CombinePathAndSpeedProfile(
    const double relative_time, const double start_s,
    DiscretizedTrajectory* ptr_discretized_trajectory) {
  ACHECK(ptr_discretized_trajectory != nullptr);
  // use varied resolution to reduce data load but also provide enough data
  // point for control module
  const double kDenseTimeResoltuion = FLAGS_trajectory_time_min_interval;
  const double kSparseTimeResolution = FLAGS_trajectory_time_max_interval;
  const double kDenseTimeSec = FLAGS_trajectory_time_high_density_period;

  if (path_data_.discretized_path().empty()) {
    AERROR << "path data is empty";
    return false;
  }

  if (speed_data_.empty()) {
    AERROR << "speed profile is empty";
    return false;
  }

  for (double cur_rel_time = 0.0; cur_rel_time < speed_data_.TotalTime();
       cur_rel_time += (cur_rel_time < kDenseTimeSec ? kDenseTimeResoltuion
                                                     : kSparseTimeResolution)) {
    common::SpeedPoint speed_point;
    if (!speed_data_.EvaluateByTime(cur_rel_time, &speed_point)) {
      AERROR << "Fail to get speed point with relative time " << cur_rel_time;
      return false;
    }

    if (speed_point.s > path_data_.discretized_path().Length()) {
      break;
    }
    common::PathPoint path_point =
        path_data_.GetPathPointWithPathS(speed_point.s);
    path_point.set__s(path_point.s + start_s);

    common::TrajectoryPoint trajectory_point;
    trajectory_point.pathpoint =(path_point);
    trajectory_point.set__v(speed_point.v);
    trajectory_point.set__a(speed_point.a);
    trajectory_point.set__relativetime(speed_point.t + relative_time);
    ptr_discretized_trajectory->AppendTrajectoryPoint(trajectory_point);
  }
  return true;
}

// TODO(all): It is a brutal way to insert the planning init point, one elegant
// way would be bypassing trajectory stitching logics somehow, or use planing
// init point from trajectory stitching to compute the trajectory at the very
// start
bool ReferenceLineInfo::AdjustTrajectoryWhichStartsFromCurrentPos(
    const common::TrajectoryPoint& planning_start_point,
    const std::vector<common::TrajectoryPoint>& trajectory,
    DiscretizedTrajectory* adjusted_trajectory) {
  ACHECK(adjusted_trajectory != nullptr);
  // find insert index by check heading
  static constexpr double kMaxAngleDiff = M_PI_2;
  const double start_point_heading = planning_start_point.pathpoint.theta;
  const double start_point_x = planning_start_point.pathpoint.x;
  const double start_point_y = planning_start_point.pathpoint.y;
  const double start_point_relative_time = planning_start_point.relativetime;

  int insert_idx = -1;
  for (size_t i = 0; i < trajectory.size(); ++i) {
    // skip trajectory_points early than planning_start_point
    if (trajectory[i].relativetime <= start_point_relative_time) {
      continue;
    }

    const double cur_point_x = trajectory[i].pathpoint.x;
    const double cur_point_y = trajectory[i].pathpoint.y;
    const double tracking_heading =
        std::atan2(cur_point_y - start_point_y, cur_point_x - start_point_x);
    if (std::fabs(common::math::AngleDiff(start_point_heading,
                                          tracking_heading)) < kMaxAngleDiff) {
      insert_idx = i;
      break;
    }
  }
  if (insert_idx == -1) {
    AERROR << "All points are behind of planning init point";
    return false;
  }

  DiscretizedTrajectory cut_trajectory(trajectory);
  cut_trajectory.erase(cut_trajectory.begin(),
                       cut_trajectory.begin() + insert_idx);
  cut_trajectory.insert(cut_trajectory.begin(), planning_start_point);

  // In class TrajectoryStitcher, the stitched point which is also the planning
  // init point is supposed have one planning_cycle_time ahead respect to
  // current timestamp as its relative time. So the relative timelines
  // of planning init point and the trajectory which start from current
  // position(relative time = 0) are the same. Therefore any conflicts on the
  // relative time including the one below should return false and inspected its
  // cause.
  if (cut_trajectory.size() > 1 && cut_trajectory.front().relativetime >=
                                       cut_trajectory[1].relativetime) {
    AERROR << "planning init point relative_time["
           << cut_trajectory.front().relativetime
           << "] larger than its next point's relative_time["
           << cut_trajectory[1].relativetime << "]";
    return false;
  }

  // In class TrajectoryStitcher, the planing_init_point is set to have s as 0,
  // so adjustment is needed to be done on the other points
  double accumulated_s = 0.0;
  for (size_t i = 1; i < cut_trajectory.size(); ++i) {
    const auto& pre_path_point = cut_trajectory[i - 1].pathpoint;
    auto* cur_path_point = &cut_trajectory[i].pathpoint;
    accumulated_s += std::sqrt((cur_path_point->x - pre_path_point.x) *
                                   (cur_path_point->x - pre_path_point.x) +
                               (cur_path_point->y - pre_path_point.y) *
                                   (cur_path_point->y - pre_path_point.y));
    cur_path_point->set__s(accumulated_s);
  }

  // reevaluate relative_time to make delta t the same
  adjusted_trajectory->clear();
  // use varied resolution to reduce data load but also provide enough data
  // point for control module
  const double kDenseTimeResoltuion = FLAGS_trajectory_time_min_interval;
  const double kSparseTimeResolution = FLAGS_trajectory_time_max_interval;
  const double kDenseTimeSec = FLAGS_trajectory_time_high_density_period;
  for (double cur_rel_time = cut_trajectory.front().relativetime;
       cur_rel_time <= cut_trajectory.back().relativetime;
       cur_rel_time += (cur_rel_time < kDenseTimeSec ? kDenseTimeResoltuion
                                                     : kSparseTimeResolution)) {
    adjusted_trajectory->AppendTrajectoryPoint(
        cut_trajectory.Evaluate(cur_rel_time));
  }
  return true;
}

void ReferenceLineInfo::SetDrivable(bool drivable) { is_drivable_ = drivable; }

bool ReferenceLineInfo::IsDrivable() const { return is_drivable_; }

bool ReferenceLineInfo::IsChangeLanePath() const {
  return !Lanes().IsOnSegment();
}

bool ReferenceLineInfo::IsNeighborLanePath() const {
  return Lanes().IsNeighborSegment();
}

std::string ReferenceLineInfo::PathSpeedDebugString() const {
  return absl::StrCat("path_data:", path_data_.DebugString(),
                      "speed_data:", speed_data_.DebugString());
}

void ReferenceLineInfo::SetTurnSignalBasedOnLaneTurnType(
    apollo_msgs::msg::ApollocommonVehicleSignal* vehicle_signal) const {
  CHECK_NOTNULL(vehicle_signal);
  if (
      vehicle_signal->turnsignal != apollo::common::VehicleSignal::TURN_NONE) {
    return;
  }
  vehicle_signal->set__turnsignal(apollo::common::VehicleSignal::TURN_NONE);

  // Set turn signal based on lane-change.
  if (IsChangeLanePath()) {
    if (Lanes().PreviousAction() == routing::ChangeLaneType::LEFT) {
      vehicle_signal->set__turnsignal(apollo::common::VehicleSignal::TURN_LEFT);
    } else if (Lanes().PreviousAction() == routing::ChangeLaneType::RIGHT) {
      vehicle_signal->set__turnsignal(apollo::common::VehicleSignal::TURN_RIGHT);
    }
    return;
  }

  // Set turn signal based on lane-borrow.
  if (path_data_.path_label().find("left") != std::string::npos) {
    vehicle_signal->set__turnsignal(apollo::common::VehicleSignal::TURN_LEFT);
    return;
  }
  if (path_data_.path_label().find("right") != std::string::npos) {
    vehicle_signal->set__turnsignal(apollo::common::VehicleSignal::TURN_RIGHT);
    return;
  }

  // Set turn signal based on lane's turn type.
  double route_s = 0.0;
  const double adc_s = adc_sl_boundary_.ends;
  for (const auto& seg : Lanes()) {
    if (route_s > adc_s + FLAGS_turn_signal_distance) {
      break;
    }
    route_s += seg.end_s - seg.start_s;
    if (route_s < adc_s) {
      continue;
    }
    const auto& turn = seg.lane->lane().turn;
    if (turn == hdmap::Lane::LEFT_TURN) {
      vehicle_signal->set__turnsignal(apollo::common::VehicleSignal::TURN_LEFT);
      break;
    } else if (turn == hdmap::Lane::RIGHT_TURN) {
      vehicle_signal->set__turnsignal(apollo::common::VehicleSignal::TURN_RIGHT);
      break;
    } else if (turn == hdmap::Lane::U_TURN) {
      // check left or right by geometry.
      auto start_xy =
          PointFactory::ToVec2d(seg.lane->GetSmoothPoint(seg.start_s));
      auto middle_xy = PointFactory::ToVec2d(
          seg.lane->GetSmoothPoint((seg.start_s + seg.end_s) / 2.0));
      auto end_xy = PointFactory::ToVec2d(seg.lane->GetSmoothPoint(seg.end_s));
      auto start_to_middle = middle_xy - start_xy;
      auto start_to_end = end_xy - start_xy;
      if (start_to_middle.CrossProd(start_to_end) < 0) {
        vehicle_signal->set__turnsignal(apollo::common::VehicleSignal::TURN_RIGHT);
      } else {
        vehicle_signal->set__turnsignal(apollo::common::VehicleSignal::TURN_LEFT);
      }
      break;
    }
  }
}

void ReferenceLineInfo::SetTurnSignal(
    const apollo::common::VehicleSignal::TurnSignal& turn_signal) {
  vehicle_signal_.set__turnsignal(turn_signal);
}

void ReferenceLineInfo::SetEmergencyLight() {
  vehicle_signal_.set__emergencylight(true);
}

void ReferenceLineInfo::ExportVehicleSignal(
    apollo_msgs::msg::ApollocommonVehicleSignal* vehicle_signal) const {
  CHECK_NOTNULL(vehicle_signal);
  *vehicle_signal = vehicle_signal_;
  SetTurnSignalBasedOnLaneTurnType(vehicle_signal);
}

bool ReferenceLineInfo::ReachedDestination() const {
  static constexpr double kDestinationDeltaS = 0.05;
  const double distance_destination = SDistanceToDestination();
  return distance_destination <= kDestinationDeltaS;
}

double ReferenceLineInfo::SDistanceToDestination() const {
  double res = std::numeric_limits<double>::max();
  const auto* dest_ptr = path_decision_.Find(FLAGS_destination_obstacle_id);
  if (!dest_ptr) {
    return res;
  }
  if (dest_ptr->LongitudinalDecision().objecttag.stop == apollo_msgs::msg::ApolloplanningObjectStop())
  {
    return res;
  }
  if (!reference_line_.IsOnLane(dest_ptr->PerceptionBoundingBox().center())) {
    return res;
  }
  const double stop_s = dest_ptr->PerceptionSLBoundary().starts +
                        dest_ptr->LongitudinalDecision().objecttag.stop.distances;
  return stop_s - adc_sl_boundary_.ends;
}

void ReferenceLineInfo::ExportDecision(
    DecisionResult* decision_result, PlanningContext* planning_context) const {
  MakeDecision(decision_result, planning_context);
  ExportVehicleSignal(&decision_result->vehiclesignal);
  auto* main_decision = &decision_result->maindecision;
  if (main_decision->task.stop != apollo_msgs::msg::ApolloplanningMainStop())
  {
    main_decision->task.stop.set__changelanetype(
        Lanes().PreviousAction());
  }
  else if (main_decision->task.cruise != apollo_msgs::msg::ApolloplanningMainCruise())
  {
    main_decision->task.cruise.set__changelanetype(
        Lanes().PreviousAction());
  }
}

void ReferenceLineInfo::MakeDecision(DecisionResult* decision_result,
                                     PlanningContext* planning_context) const {
  CHECK_NOTNULL(decision_result);
  *decision_result = apollo::planning::DecisionResult();

  // cruise by default
  //decision_result->mutable_main_decision()->mutable_cruise();

  // check stop decision
  int error_code = MakeMainStopDecision(decision_result);
  if (error_code < 0) {
    MakeEStopDecision(decision_result);
  }
  MakeMainMissionCompleteDecision(decision_result, planning_context);
  SetObjectDecisions(&decision_result->objectdecision);
}

void ReferenceLineInfo::MakeMainMissionCompleteDecision(
    DecisionResult* decision_result, PlanningContext* planning_context) const {
  if (decision_result->maindecision.task.stop == apollo_msgs::msg::ApolloplanningMainStop())
  {
    return;
  }
  auto main_stop = decision_result->maindecision.task.stop;
  if (main_stop.reasoncode != STOP_REASON_DESTINATION &&
      main_stop.reasoncode != STOP_REASON_PULL_OVER) {
    return;
  }
  const auto& adc_pos = adc_planning_point_.pathpoint;
  if (common::util::DistanceXY(adc_pos, main_stop.stoppoint) >
      FLAGS_destination_check_distance) {
    return;
  }

  auto mission_complete =
      &decision_result->maindecision.task.missioncomplete;
  if (ReachedDestination()) {
    planning_context->mutable_planning_status()->destination.set__haspasseddestination(true);
  } else {
    mission_complete->stoppoint =(main_stop.stoppoint);
    mission_complete->set__stopheading(main_stop.stopheading);
  }
}

int ReferenceLineInfo::MakeMainStopDecision(
    DecisionResult* decision_result) const {
  double min_stop_line_s = std::numeric_limits<double>::infinity();
  const Obstacle* stop_obstacle = nullptr;
  const ObjectStop* stop_decision = nullptr;

  for (const auto* obstacle : path_decision_.obstacles().Items()) {
    const auto& object_decision = obstacle->LongitudinalDecision();
    if (object_decision.objecttag.stop == apollo_msgs::msg::ApolloplanningObjectStop())
    {
      continue;
    }

    apollo::common::PointENU stop_point = object_decision.objecttag.stop.stoppoint;
    common::SLPoint stop_line_sl;
    reference_line_.XYToSLPB(stop_point, &stop_line_sl);

    double stop_line_s = stop_line_sl.s;
    if (stop_line_s < 0 || stop_line_s > reference_line_.Length()) {
      AERROR << "Ignore object:" << obstacle->Id() << " fence route_s["
             << stop_line_s << "] not in range[0, " << reference_line_.Length()
             << "]";
      continue;
    }

    // check stop_line_s vs adc_s
    if (stop_line_s < min_stop_line_s) {
      min_stop_line_s = stop_line_s;
      stop_obstacle = obstacle;
      stop_decision = &(object_decision.objecttag.stop);
    }
  }

  if (stop_obstacle != nullptr) {
    MainStop* main_stop =
        &decision_result->maindecision.task.stop;
    main_stop->set__reasoncode(stop_decision->reasoncode);
    main_stop->set__reason("stop by " + stop_obstacle->Id());
    main_stop->stoppoint.set__x(stop_decision->stoppoint.x);
    main_stop->stoppoint.set__y(stop_decision->stoppoint.y);
    main_stop->set__stopheading(stop_decision->stopheading);

    ADEBUG << " main stop obstacle id:" << stop_obstacle->Id()
           << " stop_line_s:" << min_stop_line_s << " stop_point: ("
           << stop_decision->stoppoint.x << stop_decision->stoppoint.y
           << " ) stop_heading: " << stop_decision->stopheading;

    return 1;
  }

  return 0;
}

void ReferenceLineInfo::SetObjectDecisions(
    ObjectDecisions* object_decisions) const {
  for (const auto obstacle : path_decision_.obstacles().Items()) {
    if (!obstacle->HasNonIgnoreDecision()) {
      continue;
    }
    auto* object_decision = &object_decisions->decision.emplace_back();

    object_decision->set__id(obstacle->Id());
    object_decision->set__perceptionid(obstacle->PerceptionId());
    if (obstacle->HasLateralDecision() && !obstacle->IsLateralIgnore()) {
      object_decision->objectdecision.push_back(
          obstacle->LateralDecision());
    }
    if (obstacle->HasLongitudinalDecision() &&
        !obstacle->IsLongitudinalIgnore()) {
      object_decision->objectdecision.push_back(
          obstacle->LongitudinalDecision());
    }
  }
}

void ReferenceLineInfo::ExportEngageAdvice(
    apollo_msgs::msg::ApollocommonEngageAdvice* engage_advice, PlanningContext* planning_context) const {
  static apollo_msgs::msg::ApollocommonEngageAdvice prev_advice;
  static constexpr double kMaxAngleDiff = M_PI / 6.0;

  bool engage = false;
  if (!IsDrivable()) {
    prev_advice.set__reason("Reference line not drivable");
  } else if (!is_on_reference_line_) {
    const auto& scenario_type =
        planning_context->planning_status().scenario.scenariotype;
    if (scenario_type == ScenarioConfig::PARK_AND_GO || IsChangeLanePath()) {
      // note: when is_on_reference_line_ is FALSE
      //   (1) always engage while in PARK_AND_GO scenario
      //   (2) engage when "ChangeLanePath" is picked as Drivable ref line
      //       where most likely ADC not OnLane yet
      engage = true;
    } else {
      prev_advice.set__reason("Not on reference line");
    }
  } else {
    // check heading
    auto ref_point =
        reference_line_.GetReferencePoint(adc_sl_boundary_.ends);
    if (common::math::AngleDiff(vehicle_state_.heading, ref_point.heading()) <
        kMaxAngleDiff) {
      engage = true;
    } else {
      prev_advice.set__reason("Vehicle heading is not aligned");
    }
  }

  if (engage) {
    if (vehicle_state_.drivingmode !=
        canbus::Chassis::DrivingMode::COMPLETE_AUTO_DRIVE) {
      // READY_TO_ENGAGE when in non-AUTO mode
      prev_advice.set__advice(apollo::common::EngageAdvice::READY_TO_ENGAGE);
    } else {
      // KEEP_ENGAGED when in AUTO mode
      prev_advice.set__advice(apollo::common::EngageAdvice::KEEP_ENGAGED);
    }
    prev_advice.reason = std::string();
  } else {
    if (prev_advice.advice != apollo::common::EngageAdvice::DISALLOW_ENGAGE) {
      prev_advice.set__advice(apollo::common::EngageAdvice::PREPARE_DISENGAGE);
    }
  }
  *engage_advice=(prev_advice);
}

void ReferenceLineInfo::MakeEStopDecision(
    DecisionResult* decision_result) const {
  *decision_result = apollo::planning::DecisionResult();

  apollo_msgs::msg::ApolloplanningMainEmergencyStop* main_estop =
      &decision_result->maindecision.task.estop;
  main_estop->set__reasoncode(MainEmergencyStop::ESTOP_REASON_INTERNAL_ERR);
  main_estop->set__reason("estop reason to be added");
  //main_estop->mutable_cruise_to_stop();
  main_estop->task.cruisetostop = 1;
  // set object decisions
  ObjectDecisions* object_decisions =
      &decision_result->objectdecision;
  for (const auto obstacle : path_decision_.obstacles().Items()) {
    auto* object_decision = &object_decisions->decision.emplace_back();
    object_decision->set__id(obstacle->Id());
    object_decision->set__perceptionid(obstacle->PerceptionId());
    object_decision->objectdecision.emplace_back().objecttag.avoid=1;
  }
}

hdmap::Lane::LaneTurn ReferenceLineInfo::GetPathTurnType(const double s) const {
  const double forward_buffer = 20.0;
  double route_s = 0.0;
  for (const auto& seg : Lanes()) {
    if (route_s > s + forward_buffer) {
      break;
    }
    route_s += seg.end_s - seg.start_s;
    if (route_s < s) {
      continue;
    }
    const auto& turn_type = seg.lane->lane().turn;
    if (turn_type == hdmap::Lane::LEFT_TURN ||
        turn_type == hdmap::Lane::RIGHT_TURN ||
        turn_type == hdmap::Lane::U_TURN) {
      return (apollo::hdmap::Lane::LaneTurn)turn_type;
    }
  }

  return hdmap::Lane::NO_TURN;
}

bool ReferenceLineInfo::GetIntersectionRightofWayStatus(
    const hdmap::PathOverlap& pnc_junction_overlap) const {
  if (GetPathTurnType(pnc_junction_overlap.start_s) != hdmap::Lane::NO_TURN) {
    return false;
  }

  // TODO(all): iterate exits of intersection to check/compare speed-limit
  return true;
}

int ReferenceLineInfo::GetPnCJunction(
    const double s, hdmap::PathOverlap* pnc_junction_overlap) const {
  CHECK_NOTNULL(pnc_junction_overlap);
  const std::vector<hdmap::PathOverlap>& pnc_junction_overlaps =
      reference_line_.map_path().pnc_junction_overlaps();

  static constexpr double kError = 1.0;  // meter
  for (const auto& overlap : pnc_junction_overlaps) {
    if (s >= overlap.start_s - kError && s <= overlap.end_s + kError) {
      *pnc_junction_overlap = overlap;
      return 1;
    }
  }
  return 0;
}

void ReferenceLineInfo::SetBlockingObstacle(
    const std::string& blocking_obstacle_id) {
  blocking_obstacle_ = path_decision_.Find(blocking_obstacle_id);
}

std::vector<common::SLPoint> ReferenceLineInfo::GetAllStopDecisionSLPoint()
    const {
  std::vector<common::SLPoint> result;
  for (const auto* obstacle : path_decision_.obstacles().Items()) {
    const auto& object_decision = obstacle->LongitudinalDecision();
    if (object_decision.objecttag.stop == apollo_msgs::msg::ApolloplanningObjectStop())
    {
      continue;
    }
    apollo::common::PointENU stop_point = object_decision.objecttag.stop.stoppoint;
    common::SLPoint stop_line_sl;
    reference_line_.XYToSLPB(stop_point, &stop_line_sl);
    if (stop_line_sl.s <= 0 || stop_line_sl.s >= reference_line_.Length()) {
      continue;
    }
    result.push_back(stop_line_sl);
  }

  // sort by s
  if (!result.empty()) {
    std::sort(result.begin(), result.end(),
              [](const common::SLPoint& a, const common::SLPoint& b) {
                return a.s < b.s;
              });
  }

  return result;
}

}  // namespace planning
}  // namespace apollo