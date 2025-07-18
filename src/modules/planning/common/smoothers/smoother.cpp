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

/**
 * @file
 **/

#include "modules/planning/common/smoothers/smoother.h"

#include <string>

#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/common/math/vec2d.h"
#include "modules/planning/common/planning_gflags.h"

namespace apollo {
namespace planning {

using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::common::math::Vec2d;

bool Smoother::IsCloseStop(const common::VehicleState& vehicle_state,
                           const MainStop& main_stop) {
  if (main_stop.stoppoint == apollo_msgs::msg::ApollocommonPointENU())
  {
    ADEBUG << "not close for main stop:" << main_stop;
    return false;
  }
  Vec2d current_car_pos(vehicle_state.x, vehicle_state.y);
  Vec2d stop_pos(main_stop.stoppoint.x, main_stop.stoppoint.y);
  auto stop_distance = stop_pos.DistanceTo(current_car_pos);
  if (stop_distance > FLAGS_smoother_stop_distance) {
    ADEBUG << "distance between ADC position and stop position:"
           << stop_distance;
    return false;
  }
  return true;
}

// TODO(all): extend more smooth policies into different objects
// when more use cases happens later.
apollo::common::Status Smoother::Smooth(
    const FrameHistory* frame_history, const Frame* current_frame,
    apollo_msgs::msg::ApolloplanningADCTrajectory* const current_trajectory_pb) {
  if (frame_history == nullptr) {
    const std::string msg = "frame history is null.";
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }
  if (current_frame == nullptr) {
    const std::string msg = "frame is null.";
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }
  if (current_trajectory_pb == nullptr) {
    const std::string msg = "current trajectory pb is null";
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }
  const auto& main_decision = current_trajectory_pb->decision.maindecision;
  if (main_decision.task.stop == apollo_msgs::msg::ApolloplanningMainStop())
  {
    // skip for current planning is not stop.
    ADEBUG << "skip smoothing for current planning is not stop";
    return Status::OK();
  }

  const auto& vehicle_state = current_frame->vehicle_state();
  const double max_adc_stop_speed = common::VehicleConfigHelper::Instance()
                                        ->GetConfig()
                                        .vehicleparam
                                        .maxabsspeedwhenstopped;
  if (vehicle_state.linearvelocity > max_adc_stop_speed) {
    ADEBUG << "vehicle speed:" << vehicle_state.linearvelocity
           << " skip smoothing for non-stop scenario";
    return Status::OK();
  }

  if (!IsCloseStop(vehicle_state, main_decision.task.stop)) {
    ADEBUG << "vehicle state:" << vehicle_state
           << " skip smoothing for ADC is not close to stop point";
    return Status::OK();
  }

  auto* previous_frame = (frame_history->Latest());
  if (previous_frame == nullptr) {
    const std::string msg = "previous frame is null";
    AWARN << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }
  const auto& previous_planning =
      previous_frame->current_frame_planned_trajectory();
  auto header = current_trajectory_pb->apolloheader;
  *current_trajectory_pb = previous_planning;
  current_trajectory_pb->apolloheader=(header);
  /*auto smoother_debug = current_trajectory_pb.debug
                            .planningdata
                            .smoother;
  smoother_debug->issmoothed=(true);
  smoother_debug->type=(
      planning_internal::SmootherDebug::SMOOTHER_CLOSE_STOP);*/
  return Status::OK();
}

}  // namespace planning
}  // namespace apollo