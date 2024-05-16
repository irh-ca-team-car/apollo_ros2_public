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

/**
 * @file
 **/

#include "modules/planning/tasks/deciders/open_space_decider/open_space_fallback_decider.h"

namespace apollo {
namespace planning {
using apollo::common::Status;
using apollo::common::TrajectoryPoint;
using apollo::common::math::Box2d;
using apollo::common::math::Vec2d;

OpenSpaceFallbackDecider::OpenSpaceFallbackDecider(
    const apollo_msgs::msg::ApolloplanningTaskConfig& config,
    const std::shared_ptr<DependencyInjector>& injector)
    : Decider(config, injector) {}

bool OpenSpaceFallbackDecider::QuardraticFormulaLowerSolution(const double a,
                                                              const double b,
                                                              const double c,
                                                              double* sol) {
  // quardratic formula: ax^2 + bx + c = 0, return lower solution
  // TODO(QiL): use const from common::math
  const double kEpsilon = 1e-6;
  *sol = 0.0;
  if (std::abs(a) < kEpsilon) {
    return false;
  }

  double tmp = b * b - 4 * a * c;
  if (tmp < kEpsilon) {
    return false;
  }
  double sol1 = (-b + std::sqrt(tmp)) / (2.0 * a);
  double sol2 = (-b - std::sqrt(tmp)) / (2.0 * a);

  *sol = std::abs(std::min(sol1, sol2));
  ADEBUG << "QuardraticFormulaLowerSolution finished with sol: " << *sol
         << "sol1: " << sol1 << ", sol2: " << sol2 << "a: " << a << "b: " << b
         << "c: " << c;
  return true;
}

Status OpenSpaceFallbackDecider::Process(Frame* frame) {
  std::vector<std::vector<common::math::Box2d>> predicted_bounding_rectangles;
  size_t first_collision_index = 0;
  size_t fallback_start_index = 0;

  BuildPredictedEnvironment(frame->obstacles(), predicted_bounding_rectangles);
  ADEBUG << "Numbers of obstsacles are: " << frame->obstacles().size();
  ADEBUG << "Numbers of predicted bounding rectangles are: "
         << predicted_bounding_rectangles[0].size()
         << " and : " << predicted_bounding_rectangles.size();
  if (!IsCollisionFreeTrajectory(
          frame->open_space_info().chosen_partitioned_trajectory(),
          predicted_bounding_rectangles, &fallback_start_index,
          &first_collision_index)) {
    // change flag
    frame_->mutable_open_space_info()->set_fallback_flag(true);

    // generate fallback trajectory base on current partition trajectory
    // vehicle speed is decreased to zero inside safety distance
    TrajGearPair fallback_trajectory_pair_candidate =
        frame->open_space_info().chosen_partitioned_trajectory();
    // auto* ptr_fallback_trajectory_pair =
    // frame_->mutable_open_space_info()->mutable_fallback_trajectory();
    const auto future_collision_point =
        fallback_trajectory_pair_candidate.first[first_collision_index];

    // Fallback starts from current location but with vehicle velocity
    auto fallback_start_point =
        fallback_trajectory_pair_candidate.first[fallback_start_index];
    const auto& vehicle_state = injector_->vehicle_state()->vehicle_state();
    fallback_start_point.set__v(vehicle_state.linearvelocity);

    *(frame_->mutable_open_space_info()->mutable_future_collision_point()) =
        future_collision_point;

    // min stop distance: (max_acc)
    double min_stop_distance =
        0.5 * fallback_start_point.v * fallback_start_point.v / 4.0;

    // TODO(QiL): move 1.0 to configs
    double stop_distance =
        fallback_trajectory_pair_candidate.second == canbus::Chassis::GEAR_DRIVE
            ? std::max(future_collision_point.pathpoint.s -
                           fallback_start_point.pathpoint.s - 1.0,
                       0.0)
            : std::min(future_collision_point.pathpoint.s -
                           fallback_start_point.pathpoint.s + 1.0,
                       0.0);

    ADEBUG << "stop distance : " << stop_distance;
    // const auto& vehicle_config =
    //     common::VehicleConfigHelper::Instance()->GetConfig();
    const double vehicle_max_acc = 4.0;   // vehicle_config.max_acceleration();
    const double vehicle_max_dec = -4.0;  // vehicle_config.max_deceleration();

    double stop_deceleration = 0.0;

    if (fallback_trajectory_pair_candidate.second ==
        canbus::Chassis::GEAR_REVERSE) {
      stop_deceleration =
          std::min(fallback_start_point.v * fallback_start_point.v /
                       (2.0 * (stop_distance + 1e-6)),
                   vehicle_max_acc);
      stop_distance = std::min(-1 * min_stop_distance, stop_distance);
    } else {
      stop_deceleration =
          std::max(-fallback_start_point.v * fallback_start_point.v /
                       (2.0 * (stop_distance + 1e-6)),
                   vehicle_max_dec);
      stop_distance = std::max(min_stop_distance, stop_distance);
    }

    ADEBUG << "stop_deceleration: " << stop_deceleration;

    // Search stop index in chosen trajectory by distance
    size_t stop_index = fallback_start_index;

    for (size_t i = fallback_start_index;
         i < fallback_trajectory_pair_candidate.first.NumOfPoints(); ++i) {
      if (std::abs(
              fallback_trajectory_pair_candidate.first[i].pathpoint.s) >=
          std::abs(fallback_start_point.pathpoint.s + stop_distance)) {
        stop_index = i;
        break;
      }
    }

    ADEBUG << "stop index before is: " << stop_index
           << "; fallback_start index before is: " << fallback_start_index;

    for (size_t i = 0; i < fallback_start_index; ++i) {
      fallback_trajectory_pair_candidate.first[i].set__v(
          fallback_start_point.v);
      fallback_trajectory_pair_candidate.first[i].set__a(stop_deceleration);
    }

    // TODO(QiL): refine the logic and remove redundant code, change 0.5 to from
    // loading optimizer configs

    // If stop_index == fallback_start_index;
    if (fallback_start_index == stop_index) {
      // 1. Set fallback start speed to 0, acceleration to max acceleration.
      AINFO << "Stop distance within safety buffer, stop now!";
      fallback_start_point.set__v(0.0);
      fallback_start_point.set__a(0.0);
      fallback_trajectory_pair_candidate.first[stop_index].set__v(0.0);
      fallback_trajectory_pair_candidate.first[stop_index].set__a(0.0);

      // 2. Trim all trajectory points after stop index
      fallback_trajectory_pair_candidate.first.erase(
          fallback_trajectory_pair_candidate.first.begin() + stop_index + 1,
          fallback_trajectory_pair_candidate.first.end());

      // 3. AppendTrajectoryPoint with same location but zero velocity
      for (int i = 0; i < 20; ++i) {
        common::TrajectoryPoint trajectory_point(
            fallback_trajectory_pair_candidate.first[stop_index]);
        trajectory_point.set__relativetime(
            i * 0.5 + 0.5 +
            fallback_trajectory_pair_candidate.first[stop_index]
                .relativetime);
        fallback_trajectory_pair_candidate.first.AppendTrajectoryPoint(
            trajectory_point);
      }

      *(frame_->mutable_open_space_info()->mutable_fallback_trajectory()) =
          fallback_trajectory_pair_candidate;

      return Status::OK();
    }

    ADEBUG << "before change, size : "
           << fallback_trajectory_pair_candidate.first.size()
           << ", first index information : "
           << fallback_trajectory_pair_candidate.first[0]
           << ", second index information : "
           << fallback_trajectory_pair_candidate.first[1];

    // If stop_index > fallback_start_index

    for (size_t i = fallback_start_index; i <= stop_index; ++i) {
      double new_relative_time = 0.0;
      double temp_v = 0.0;
      double c =
          -2.0 * fallback_trajectory_pair_candidate.first[i].pathpoint.s;

      if (QuardraticFormulaLowerSolution(stop_deceleration,
                                         2.0 * fallback_start_point.v, c,
                                         &new_relative_time) &&
          std::abs(
              fallback_trajectory_pair_candidate.first[i].pathpoint.s) <=
              std::abs(stop_distance)) {
        ADEBUG << "new_relative_time" << new_relative_time;
        temp_v =
            fallback_start_point.v + stop_deceleration * new_relative_time;
        // speed limit
        if (std::abs(temp_v) < 1.0) {
          fallback_trajectory_pair_candidate.first[i].set__v(temp_v);
        } else {
          fallback_trajectory_pair_candidate.first[i].set__v(
              temp_v / std::abs(temp_v) * 1.0);
        }
        fallback_trajectory_pair_candidate.first[i].set__a(stop_deceleration);

        fallback_trajectory_pair_candidate.first[i].set__relativetime(
            new_relative_time);
      } else {
        AINFO << "QuardraticFormulaLowerSolution solving failed, stop "
                 "immediately!";

        if (i != 0) {
          fallback_trajectory_pair_candidate.first[i]
              .pathpoint=
              (
                  fallback_trajectory_pair_candidate.first[i - 1].pathpoint);
          fallback_trajectory_pair_candidate.first[i].set__v(0.0);
          fallback_trajectory_pair_candidate.first[i].set__a(0.0);
          fallback_trajectory_pair_candidate.first[i].set__relativetime(
              fallback_trajectory_pair_candidate.first[i - 1].relativetime +
              0.5);
        } else {
          fallback_trajectory_pair_candidate.first[i].set__v(0.0);
          fallback_trajectory_pair_candidate.first[i].set__a(0.0);
        }
      }
    }

    ADEBUG << "fallback start point after changes: "
           << fallback_start_point;

    ADEBUG << "stop index: " << stop_index;
    ADEBUG << "fallback start index: " << fallback_start_index;

    // 2. Erase afterwards
    fallback_trajectory_pair_candidate.first.erase(
        fallback_trajectory_pair_candidate.first.begin() + stop_index + 1,
        fallback_trajectory_pair_candidate.first.end());

    // 3. AppendTrajectoryPoint with same location but zero velocity
    for (int i = 0; i < 20; ++i) {
      common::TrajectoryPoint trajectory_point(
          fallback_trajectory_pair_candidate.first[stop_index]);
      trajectory_point.set__relativetime(
          i * 0.5 + 0.5 +
          fallback_trajectory_pair_candidate.first[stop_index].relativetime);
      fallback_trajectory_pair_candidate.first.AppendTrajectoryPoint(
          trajectory_point);
    }

    *(frame_->mutable_open_space_info()->mutable_fallback_trajectory()) =
        fallback_trajectory_pair_candidate;
  } else {
    frame_->mutable_open_space_info()->set_fallback_flag(false);
  }

  return Status::OK();
}

void OpenSpaceFallbackDecider::BuildPredictedEnvironment(
    const std::vector<const Obstacle*>& obstacles,
    std::vector<std::vector<common::math::Box2d>>&
        predicted_bounding_rectangles) {
  predicted_bounding_rectangles.clear();
  double relative_time = 0.0;
  while (relative_time < config_.taskconfig.openspacefallbackdeciderconfig
                             .openspacepredictiontimeperiod) {
    std::vector<Box2d> predicted_env;
    for (const Obstacle* obstacle : obstacles) {
      if (!obstacle->IsVirtual()) {
        TrajectoryPoint point = obstacle->GetPointAtTime(relative_time);
        Box2d box = obstacle->GetBoundingBox(point);
        predicted_env.push_back(std::move(box));
      }
    }
    predicted_bounding_rectangles.emplace_back(std::move(predicted_env));
    relative_time += FLAGS_trajectory_time_resolution;
  }
}

bool OpenSpaceFallbackDecider::IsCollisionFreeTrajectory(
    const TrajGearPair& trajectory_gear_pair,
    const std::vector<std::vector<common::math::Box2d>>&
        predicted_bounding_rectangles,
    size_t* current_index, size_t* first_collision_index) {
  // prediction time resolution: FLAGS_trajectory_time_resolution
  const auto& vehicle_config =
      common::VehicleConfigHelper::Instance()->GetConfig();
  double ego_length = vehicle_config.vehicleparam.length;
  double ego_width = vehicle_config.vehicleparam.width;
  auto trajectory_pb = trajectory_gear_pair.first;
  const size_t point_size = trajectory_pb.NumOfPoints();

  *current_index = trajectory_pb.QueryLowerBoundPoint(0.0);

  for (size_t i = *current_index; i < point_size; ++i) {
    const auto& trajectory_point = trajectory_pb.TrajectoryPointAt(i);
    double ego_theta = trajectory_point.pathpoint.theta;
    Box2d ego_box(
        {trajectory_point.pathpoint.x, trajectory_point.pathpoint.y},
        ego_theta, ego_length, ego_width);
    double shift_distance =
        ego_length / 2.0 - vehicle_config.vehicleparam.backedgetocenter;
    Vec2d shift_vec{shift_distance * std::cos(ego_theta),
                    shift_distance * std::sin(ego_theta)};
    ego_box.Shift(shift_vec);
    size_t predicted_time_horizon = predicted_bounding_rectangles.size();
    for (size_t j = 0; j < predicted_time_horizon; j++) {
      for (const auto& obstacle_box : predicted_bounding_rectangles[j]) {
        if (ego_box.HasOverlap(obstacle_box)) {
          ADEBUG << "HasOverlap(obstacle_box) [" << i << "]";
          const auto& vehicle_state = frame_->vehicle_state();
          Vec2d vehicle_vec({vehicle_state.x, vehicle_state.y});
          // remove points in previous trajectory
          if (std::abs(trajectory_point.relativetime -
                       static_cast<double>(j) *
                           FLAGS_trajectory_time_resolution) <
                  config_.taskconfig.openspacefallbackdeciderconfig
                      .openspacefallbackcollisiontimebuffer &&
              trajectory_point.relativetime > 0.0) {
            ADEBUG << "first_collision_index: [" << i << "]";
            *first_collision_index = i;
            return false;
          }
        }
      }
    }
  }

  return true;
}
}  // namespace planning
}  // namespace apollo
