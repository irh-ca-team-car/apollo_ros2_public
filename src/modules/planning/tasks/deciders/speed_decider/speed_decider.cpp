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

#include "modules/planning/tasks/deciders/speed_decider/speed_decider.h"

#include <algorithm>
#include <memory>

#include "cyber/common/log.h"
#include "cyber/time/clock.h"
#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/common/util/util.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/planning/common/planning_context.h"
#include "modules/planning/common/planning_gflags.h"
#include "modules/planning/proto/decision.pb.h"
#include "modules/planning/tasks/utils/st_gap_estimator.h"

namespace apollo {
namespace planning {

using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::common::VehicleConfigHelper;
using apollo::common::math::Vec2d;
using apollo::cyber::Clock;

SpeedDecider::SpeedDecider(const apollo_msgs::msg::ApolloplanningTaskConfig& config,
                           const std::shared_ptr<DependencyInjector>& injector)
    : Task(config, injector) {}

common::Status SpeedDecider::Execute(Frame* frame,
                                     ReferenceLineInfo* reference_line_info) {
  Task::Execute(frame, reference_line_info);
  init_point_ = frame_->PlanningStartPoint();
  adc_sl_boundary_ = reference_line_info_->AdcSlBoundary();
  reference_line_ = &reference_line_info_->reference_line();
  if (!MakeObjectDecision(reference_line_info->speed_data(),
                          reference_line_info->path_decision())
           .ok()) {
    const std::string msg = "Get object decision by speed profile failed.";
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }
  return Status::OK();
}

SpeedDecider::STLocation SpeedDecider::GetSTLocation(
    const PathDecision* const path_decision, const SpeedData& speed_profile,
    const STBoundary& st_boundary) const {
  if (st_boundary.IsEmpty()) {
    return BELOW;
  }

  STLocation st_location = BELOW;
  bool st_position_set = false;
  const double start_t = st_boundary.min_t();
  const double end_t = st_boundary.max_t();
  for (size_t i = 0; i + 1 < speed_profile.size(); ++i) {
    const STPoint curr_st(speed_profile[i].s, speed_profile[i].t);
    const STPoint next_st(speed_profile[i + 1].s, speed_profile[i + 1].t);
    if (curr_st.t() < start_t && next_st.t() < start_t) {
      continue;
    }
    if (curr_st.t() > end_t) {
      break;
    }

    if (!FLAGS_use_st_drivable_boundary) {
      common::math::LineSegment2d speed_line(curr_st, next_st);
      if (st_boundary.HasOverlap(speed_line)) {
        ADEBUG << "speed profile cross st_boundaries.";
        st_location = CROSS;

        if (!FLAGS_use_st_drivable_boundary) {
          if (st_boundary.boundary_type() ==
              STBoundary::BoundaryType::KEEP_CLEAR) {
            if (!CheckKeepClearCrossable(path_decision, speed_profile,
                                         st_boundary)) {
              st_location = BELOW;
            }
          }
        }
        break;
      }
    }

    // note: st_position can be calculated by checking two st points once
    //       but we need iterate all st points to make sure there is no CROSS
    if (!st_position_set) {
      if (start_t < next_st.t() && curr_st.t() < end_t) {
        STPoint bd_point_front = st_boundary.upper_points().front();
        double side = common::math::CrossProd(bd_point_front, curr_st, next_st);
        st_location = side < 0.0 ? ABOVE : BELOW;
        st_position_set = true;
      }
    }
  }
  return st_location;
}

bool SpeedDecider::CheckKeepClearCrossable(
    const PathDecision* const path_decision, const SpeedData& speed_profile,
    const STBoundary& keep_clear_st_boundary) const {
  UNUSED(path_decision);
  bool keep_clear_crossable = true;

  const auto& last_speed_point = speed_profile.back();
  double last_speed_point_v = 0.0;
  if (last_speed_point.v!=0) {
    last_speed_point_v = last_speed_point.v;
  } else {
    const size_t len = speed_profile.size();
    if (len > 1) {
      const auto& last_2nd_speed_point = speed_profile[len - 2];
      last_speed_point_v = (last_speed_point.s - last_2nd_speed_point.s) /
                           (last_speed_point.t - last_2nd_speed_point.t);
    }
  }
  static constexpr double kKeepClearSlowSpeed = 2.5;  // m/s
  ADEBUG << "last_speed_point_s[" << last_speed_point.s
         << "] st_boundary.max_s[" << keep_clear_st_boundary.max_s()
         << "] last_speed_point_v[" << last_speed_point_v << "]";
  if (last_speed_point.s <= keep_clear_st_boundary.max_s() &&
      last_speed_point_v < kKeepClearSlowSpeed) {
    keep_clear_crossable = false;
  }
  return keep_clear_crossable;
}

bool SpeedDecider::CheckKeepClearBlocked(
    const PathDecision* const path_decision,
    const Obstacle& keep_clear_obstacle) const {
  bool keep_clear_blocked = false;

  // check if overlap with other stop wall
  for (const auto* obstacle : path_decision->obstacles().Items()) {
    if (obstacle->Id() == keep_clear_obstacle.Id()) {
      continue;
    }
    const double obstacle_start_s = obstacle->PerceptionSLBoundary().starts;
    const double adc_length =
        VehicleConfigHelper::GetConfig().vehicleparam.length;
    const double distance =
        obstacle_start_s - keep_clear_obstacle.PerceptionSLBoundary().ends;

    if (obstacle->IsBlockingObstacle() && distance > 0 &&
        distance < (adc_length / 2)) {
      keep_clear_blocked = true;
      break;
    }
  }
  return keep_clear_blocked;
}

bool SpeedDecider::IsFollowTooClose(const Obstacle& obstacle) const {
  if (!obstacle.IsBlockingObstacle()) {
    return false;
  }

  if (obstacle.path_st_boundary().min_t() > 0.0) {
    return false;
  }
  const double obs_speed = obstacle.speed();
  const double ego_speed = init_point_.v;
  if (obs_speed > ego_speed) {
    return false;
  }
  const double distance =
      obstacle.path_st_boundary().min_s() - FLAGS_min_stop_distance_obstacle;
  static constexpr double lane_follow_max_decel = 3.0;
  static constexpr double lane_change_max_decel = 3.0;
  auto* planning_status = &injector_->planning_context()
                              ->mutable_planning_status()
                              ->changelane;
  double distance_numerator = std::pow((ego_speed - obs_speed), 2) * 0.5;
  double distance_denominator = lane_follow_max_decel;
  if (planning_status->status == ChangeLaneStatus::IN_CHANGE_LANE) {
    distance_denominator = lane_change_max_decel;
  }
  return distance < distance_numerator / distance_denominator;
}

Status SpeedDecider::MakeObjectDecision(
    const SpeedData& speed_profile, PathDecision* const path_decision) const {
  if (speed_profile.size() < 2) {
    const std::string msg = "dp_st_graph failed to get speed profile.";
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }

  for (const auto* obstacle : path_decision->obstacles().Items()) {
    auto* mutable_obstacle = path_decision->Find(obstacle->Id());
    const auto& boundary = mutable_obstacle->path_st_boundary();

    if (boundary.IsEmpty() || boundary.max_s() < 0.0 ||
        boundary.max_t() < 0.0 ||
        boundary.min_t() >= speed_profile.back().t) {
      AppendIgnoreDecision(mutable_obstacle);
      continue;
    }
    if (obstacle->HasLongitudinalDecision()) {
      AppendIgnoreDecision(mutable_obstacle);
      continue;
    }

    // for Virtual obstacle, skip if center point NOT "on lane"
    if (obstacle->IsVirtual()) {
      const auto& obstacle_box = obstacle->PerceptionBoundingBox();
      if (!reference_line_->IsOnLane(obstacle_box.center())) {
        continue;
      }
    }

    // always STOP for pedestrian
    if (CheckStopForPedestrian(*mutable_obstacle)) {
      apollo_msgs::msg::ApolloplanningObjectDecisionType stop_decision;
      if (CreateStopDecision(*mutable_obstacle, &stop_decision,
                             -FLAGS_min_stop_distance_obstacle)) {
        mutable_obstacle->AddLongitudinalDecision("dp_st_graph/pedestrian",
                                                  stop_decision);
      }
      continue;
    }

    auto location = GetSTLocation(path_decision, speed_profile, boundary);

    if (!FLAGS_use_st_drivable_boundary) {
      if (boundary.boundary_type() == STBoundary::BoundaryType::KEEP_CLEAR) {
        if (CheckKeepClearBlocked(path_decision, *obstacle)) {
          location = BELOW;
        }
      }
    }

    switch (location) {
      case BELOW:
        if (boundary.boundary_type() == STBoundary::BoundaryType::KEEP_CLEAR) {
          apollo_msgs::msg::ApolloplanningObjectDecisionType stop_decision;
          if (CreateStopDecision(*mutable_obstacle, &stop_decision, 0.0)) {
            mutable_obstacle->AddLongitudinalDecision("dp_st_graph/keep_clear",
                                                      stop_decision);
          }
        } else if (CheckIsFollow(*obstacle, boundary)) {
          // stop for low_speed decelerating
          if (IsFollowTooClose(*mutable_obstacle)) {
            apollo_msgs::msg::ApolloplanningObjectDecisionType stop_decision;
            if (CreateStopDecision(*mutable_obstacle, &stop_decision,
                                   -FLAGS_min_stop_distance_obstacle)) {
              mutable_obstacle->AddLongitudinalDecision("dp_st_graph/too_close",
                                                        stop_decision);
            }
          } else {  // high speed or low speed accelerating
            // FOLLOW decision
            apollo_msgs::msg::ApolloplanningObjectDecisionType follow_decision;
            if (CreateFollowDecision(*mutable_obstacle, &follow_decision)) {
              mutable_obstacle->AddLongitudinalDecision("dp_st_graph",
                                                        follow_decision);
            }
          }
        } else {
          // YIELD decision
          apollo_msgs::msg::ApolloplanningObjectDecisionType yield_decision;
          if (CreateYieldDecision(*mutable_obstacle, &yield_decision)) {
            mutable_obstacle->AddLongitudinalDecision("dp_st_graph",
                                                      yield_decision);
          }
        }
        break;
      case ABOVE:
        if (boundary.boundary_type() == STBoundary::BoundaryType::KEEP_CLEAR) {
          apollo_msgs::msg::ApolloplanningObjectDecisionType ignore;
          ignore.objecttag.ignore = 1;
          mutable_obstacle->AddLongitudinalDecision("dp_st_graph", ignore);
        } else {
          // OVERTAKE decision
          apollo_msgs::msg::ApolloplanningObjectDecisionType overtake_decision;
          if (CreateOvertakeDecision(*mutable_obstacle, &overtake_decision)) {
            mutable_obstacle->AddLongitudinalDecision("dp_st_graph/overtake",
                                                      overtake_decision);
          }
        }
        break;
      case CROSS:
        if (mutable_obstacle->IsBlockingObstacle()) {
          apollo_msgs::msg::ApolloplanningObjectDecisionType stop_decision;
          if (CreateStopDecision(*mutable_obstacle, &stop_decision,
                                 -FLAGS_min_stop_distance_obstacle)) {
            mutable_obstacle->AddLongitudinalDecision("dp_st_graph/cross",
                                                      stop_decision);
          }
          const std::string msg = absl::StrCat(
              "Failed to find a solution for crossing obstacle: ",
              mutable_obstacle->Id());
          AERROR << msg;
          return Status(ErrorCode::PLANNING_ERROR, msg);
        }
        break;
      default:
        AERROR << "Unknown position:" << location;
    }
    AppendIgnoreDecision(mutable_obstacle);
  }

  return Status::OK();
}

void SpeedDecider::AppendIgnoreDecision(Obstacle* obstacle) const {
  apollo_msgs::msg::ApolloplanningObjectDecisionType ignore_decision;
  ignore_decision.objecttag.ignore=1;
  if (!obstacle->HasLongitudinalDecision()) {
    obstacle->AddLongitudinalDecision("dp_st_graph", ignore_decision);
  }
  if (!obstacle->HasLateralDecision()) {
    obstacle->AddLateralDecision("dp_st_graph", ignore_decision);
  }
}

bool SpeedDecider::CreateStopDecision(const Obstacle& obstacle,
                                      apollo_msgs::msg::ApolloplanningObjectDecisionType* const stop_decision,
                                      double stop_distance) const {
  const auto& boundary = obstacle.path_st_boundary();

  // TODO(all): this is a bug! Cannot mix reference s and path s!
  // Replace boundary.min_s() with computed reference line s
  // fence is set according to reference line s.
  double fence_s = adc_sl_boundary_.ends + boundary.min_s() + stop_distance;
  if (boundary.boundary_type() == STBoundary::BoundaryType::KEEP_CLEAR) {
    fence_s = obstacle.PerceptionSLBoundary().starts;
  }
  const double main_stop_s =
      reference_line_info_->path_decision()->stop_reference_line_s();
  if (main_stop_s < fence_s) {
    ADEBUG << "Stop fence is further away, ignore.";
    return false;
  }

  const auto fence_point = reference_line_->GetReferencePoint(fence_s);

  // set STOP decision
  auto* stop = &stop_decision->objecttag.stop;
  stop->set__distances(stop_distance);
  auto* stop_point = &stop->stoppoint;
  stop_point->set__x(fence_point.x());
  stop_point->set__y(fence_point.y());
  stop_point->set__z(0.0);
  stop->set__stopheading(fence_point.heading());

  if (boundary.boundary_type() == STBoundary::BoundaryType::KEEP_CLEAR) {
    stop->set__reasoncode(StopReasonCode::STOP_REASON_CLEAR_ZONE);
  }

  apollo::perception::PerceptionObstacle::Type obstacle_type = (apollo::perception::PerceptionObstacle::Type)obstacle.Perception().type;
  ADEBUG << "STOP: obstacle_id[" << obstacle.Id() << "] obstacle_type["
         << apollo::perception::PerceptionObstacle::Type_Name(obstacle_type) << "]";

  return true;
}

bool SpeedDecider::CreateFollowDecision(
    const Obstacle& obstacle, apollo_msgs::msg::ApolloplanningObjectDecisionType* const follow_decision) const {
  const double follow_speed = init_point_.v;
  const double follow_distance_s =
      -StGapEstimator::EstimateProperFollowingGap(follow_speed);

  const auto& boundary = obstacle.path_st_boundary();
  const double reference_s =
      adc_sl_boundary_.ends + boundary.min_s() + follow_distance_s;
  const double main_stop_s =
      reference_line_info_->path_decision()->stop_reference_line_s();
  if (main_stop_s < reference_s) {
    ADEBUG << "Follow reference_s is further away, ignore.";
    return false;
  }

  auto ref_point = reference_line_->GetReferencePoint(reference_s);

  // set FOLLOW decision
  auto* follow = &follow_decision->objecttag.follow;
  follow->set__distances(follow_distance_s);
  auto* fence_point = &follow->fencepoint;
  fence_point->set__x(ref_point.x());
  fence_point->set__y(ref_point.y());
  fence_point->set__z(0.0);
  follow->set__fenceheading(ref_point.heading());

  apollo::perception::PerceptionObstacle::Type obstacle_type = (apollo::perception::PerceptionObstacle::Type)obstacle.Perception().type;
  ADEBUG << "FOLLOW: obstacle_id[" << obstacle.Id() << "] obstacle_type["
         << apollo::perception::PerceptionObstacle::Type_Name(obstacle_type) << "]";

  return true;
}

bool SpeedDecider::CreateYieldDecision(
    const Obstacle& obstacle, apollo_msgs::msg::ApolloplanningObjectDecisionType* const yield_decision) const {
  apollo::perception::PerceptionObstacle::Type obstacle_type = (apollo::perception::PerceptionObstacle::Type)obstacle.Perception().type;
  double yield_distance = StGapEstimator::EstimateProperYieldingGap();

  const auto& obstacle_boundary = obstacle.path_st_boundary();
  const double yield_distance_s =
      std::max(-obstacle_boundary.min_s(), -yield_distance);

  const double reference_line_fence_s =
      adc_sl_boundary_.ends + obstacle_boundary.min_s() + yield_distance_s;
  const double main_stop_s =
      reference_line_info_->path_decision()->stop_reference_line_s();
  if (main_stop_s < reference_line_fence_s) {
    ADEBUG << "Yield reference_s is further away, ignore.";
    return false;
  }

  auto ref_point = reference_line_->GetReferencePoint(reference_line_fence_s);

  // set YIELD decision
  auto* yield = &yield_decision->objecttag.yieldd;
  yield->set__distances(yield_distance_s);
  yield->fencepoint.set__x(ref_point.x());
  yield->fencepoint.set__y(ref_point.y());
  yield->fencepoint.set__z(0.0);
  yield->set__fenceheading(ref_point.heading());

  ADEBUG << "YIELD: obstacle_id[" << obstacle.Id() << "] obstacle_type["
         << apollo::perception::PerceptionObstacle::Type_Name(obstacle_type) << "]";

  return true;
}

bool SpeedDecider::CreateOvertakeDecision(
    const Obstacle &obstacle,
    apollo_msgs::msg::ApolloplanningObjectDecisionType *const overtake_decision) const
{
  const auto& velocity = obstacle.Perception().velocity;
  const double obstacle_speed =
      common::math::Vec2d::CreateUnitVec2d(init_point_.pathpoint.theta)
          .InnerProd(Vec2d(velocity.x, velocity.y));

  const double overtake_distance_s =
      StGapEstimator::EstimateProperOvertakingGap(obstacle_speed,
                                                  init_point_.v);

  const auto& boundary = obstacle.path_st_boundary();
  const double reference_line_fence_s =
      adc_sl_boundary_.ends + boundary.min_s() + overtake_distance_s;
  const double main_stop_s =
      reference_line_info_->path_decision()->stop_reference_line_s();
  if (main_stop_s < reference_line_fence_s) {
    ADEBUG << "Overtake reference_s is further away, ignore.";
    return false;
  }

  auto ref_point = reference_line_->GetReferencePoint(reference_line_fence_s);

  // set OVERTAKE decision
  auto* overtake = &overtake_decision->objecttag.overtake;
  overtake->set__distances(overtake_distance_s);
  overtake->fencepoint.set__x(ref_point.x());
  overtake->fencepoint.set__y(ref_point.y());
  overtake->fencepoint.set__z(0.0);
  overtake->set__fenceheading(ref_point.heading());

  apollo::perception::PerceptionObstacle::Type obstacle_type = (apollo::perception::PerceptionObstacle::Type)obstacle.Perception().type;
  ADEBUG << "OVERTAKE: obstacle_id[" << obstacle.Id() << "] obstacle_type["
         << apollo::perception::PerceptionObstacle::Type_Name(obstacle_type) << "]";

  return true;
}

bool SpeedDecider::CheckIsFollow(const Obstacle& obstacle,
                                 const STBoundary& boundary) const {
  const double obstacle_l_distance =
      std::min(std::fabs(obstacle.PerceptionSLBoundary().startl),
               std::fabs(obstacle.PerceptionSLBoundary().endl));
  if (obstacle_l_distance > FLAGS_follow_min_obs_lateral_distance) {
    return false;
  }

  // move towards adc
  if (boundary.bottom_left_point().s() > boundary.bottom_right_point().s()) {
    return false;
  }

  static constexpr double kFollowTimeEpsilon = 1e-3;
  static constexpr double kFollowCutOffTime = 0.5;
  if (boundary.min_t() > kFollowCutOffTime ||
      boundary.max_t() < kFollowTimeEpsilon) {
    return false;
  }

  // cross lane but be moving to different direction
  if (boundary.max_t() - boundary.min_t() < FLAGS_follow_min_time_sec) {
    return false;
  }

  return true;
}

bool SpeedDecider::CheckStopForPedestrian(const Obstacle& obstacle) const {
  const auto& perception_obstacle = obstacle.Perception();
  if (perception_obstacle.type != apollo::perception::PerceptionObstacle::PEDESTRIAN) {
    return false;
  }

  const auto& obstacle_sl_boundary = obstacle.PerceptionSLBoundary();
  if (obstacle_sl_boundary.ends < adc_sl_boundary_.starts) {
    return false;
  }

  // read pedestrian stop time from PlanningContext
  auto* mutable_speed_decider_status = &injector_->planning_context()
                                           ->mutable_planning_status()
                                           ->speeddecider;
  std::unordered_map<std::string, double> stop_time_map;
  for (const auto& pedestrian_stop_time :
       mutable_speed_decider_status->pedestrianstoptime) {
    stop_time_map[pedestrian_stop_time.obstacleid] =
        pedestrian_stop_time.stoptimestampsec;
  }

  const std::string& obstacle_id = obstacle.Id();

  // update stop timestamp on static pedestrian for watch timer
  // check on stop timer for static pedestrians
  static constexpr double kSDistanceStartTimer = 10.0;
  static constexpr double kMaxStopSpeed = 0.3;
  static constexpr double kPedestrianStopTimeout = 4.0;

  bool result = true;
  if (obstacle.path_st_boundary().min_s() < kSDistanceStartTimer) {
    const auto obstacle_speed = std::hypot(perception_obstacle.velocity.x,
                                           perception_obstacle.velocity.y);
    if (obstacle_speed > kMaxStopSpeed) {
      stop_time_map.erase(obstacle_id);
    } else {
      if (stop_time_map.count(obstacle_id) == 0) {
        // add timestamp
        stop_time_map[obstacle_id] = Clock::NowInSeconds();
        ADEBUG << "add timestamp: obstacle_id[" << obstacle_id << "] timestamp["
               << Clock::NowInSeconds() << "]";
      } else {
        // check timeout
        double stop_timer = Clock::NowInSeconds() - stop_time_map[obstacle_id];
        ADEBUG << "stop_timer: obstacle_id[" << obstacle_id << "] stop_timer["
               << stop_timer << "]";
        if (stop_timer >= kPedestrianStopTimeout) {
          result = false;
        }
      }
    }
  }

  // write pedestrian stop time to PlanningContext
  mutable_speed_decider_status->pedestrianstoptime.clear();
  for (const auto& stop_time : stop_time_map) {
    auto pedestrian_stop_time =
        &mutable_speed_decider_status->pedestrianstoptime.emplace_back();
    pedestrian_stop_time->set__obstacleid(stop_time.first);
    pedestrian_stop_time->set__stoptimestampsec(stop_time.second);
  }
  return result;
}

}  // namespace planning
}  // namespace apollo
