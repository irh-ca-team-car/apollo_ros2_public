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

#include "modules/planning/scenarios/park_and_go/stage_adjust.h"

#include "cyber/common/log.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/planning/common/frame.h"
#include "modules/planning/common/planning_context.h"
#include "modules/planning/common/util/common.h"
#include "modules/planning/scenarios/util/util.h"
#include "modules/planning/tasks/deciders/path_bounds_decider/path_bounds_decider.h"

namespace apollo {
namespace planning {
namespace scenario {
namespace park_and_go {

using apollo::common::TrajectoryPoint;

Stage::StageStatus ParkAndGoStageAdjust::Process(
    const TrajectoryPoint& planning_init_point, Frame* frame) {
  UNUSED(planning_init_point);
  ADEBUG << "stage: Adjust";
  CHECK_NOTNULL(frame);

  scenario_config_=(GetContext()->scenario_config);

  frame->mutable_open_space_info()->set_is_on_open_space_trajectory(true);
  bool plan_ok = ExecuteTaskOnOpenSpace(frame);
  if (!plan_ok) {
    AERROR << "ParkAndGoStageAdjust planning error";
    return StageStatus::ERROR;
  }
  const bool is_ready_to_cruise = scenario::util::CheckADCReadyToCruise(
      injector_->vehicle_state(), frame, scenario_config_);

  bool is_end_of_trajectory = false;
  const auto& history_frame = injector_->frame_history()->Latest();
  if (history_frame) {
    const auto& trajectory_points =
        history_frame->current_frame_planned_trajectory().trajectorypoint;
    if (!trajectory_points.empty()) {
      is_end_of_trajectory =
          (trajectory_points.rbegin()->relativetime < 0.0);
    }
  }

  if (!is_ready_to_cruise && !is_end_of_trajectory) {
    return StageStatus::RUNNING;
  }
  return FinishStage();
}

Stage::StageStatus ParkAndGoStageAdjust::FinishStage() {
  const auto vehicle_status = injector_->vehicle_state();
  ADEBUG << vehicle_status->steering_percentage();
  if (std::fabs(vehicle_status->steering_percentage()) <
      scenario_config_.maxsteeringpercentagewhencruise) {
    next_stage_ = ScenarioConfig::PARK_AND_GO_CRUISE;
  } else {
    ResetInitPostion();
    next_stage_ = ScenarioConfig::PARK_AND_GO_PRE_CRUISE;
  }
  return Stage::FINISHED;
}

void ParkAndGoStageAdjust::ResetInitPostion() {
  auto* park_and_go_status = &injector_->planning_context()
                                 ->mutable_planning_status()
                                 ->parkandgo;
  park_and_go_status->adcinitposition.set__x(
      injector_->vehicle_state()->x());
  park_and_go_status->adcinitposition.set__y(
      injector_->vehicle_state()->y());
  park_and_go_status->adcinitposition.set__z(0.0);
  park_and_go_status->set__adcinitheading(
      injector_->vehicle_state()->heading());
}

}  // namespace park_and_go
}  // namespace scenario
}  // namespace planning
}  // namespace apollo
