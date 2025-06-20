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

#include "modules/planning/scenarios/park_and_go/stage_check.h"

namespace apollo {
namespace planning {
namespace scenario {
namespace park_and_go {

using apollo::common::TrajectoryPoint;

Stage::StageStatus ParkAndGoStageCheck::Process(
    const TrajectoryPoint& planning_init_point, Frame* frame) {
  UNUSED(planning_init_point);
  ADEBUG << "stage: Check";
  CHECK_NOTNULL(frame);

  scenario_config_=(GetContext()->scenario_config);
  ADCInitStatus();
  frame->mutable_open_space_info()->set_is_on_open_space_trajectory(true);
  bool plan_ok = ExecuteTaskOnOpenSpace(frame);
  if (!plan_ok) {
    AERROR << "ParkAndGoStageAdjust planning error";
    return StageStatus::ERROR;
  }

  bool ready_to_cruise = scenario::util::CheckADCReadyToCruise(
      injector_->vehicle_state(), frame, scenario_config_);
  return FinishStage(ready_to_cruise);
}

Stage::StageStatus ParkAndGoStageCheck::FinishStage(const bool success) {
  if (success) {
    next_stage_ = ScenarioConfig::PARK_AND_GO_CRUISE;
  } else {
    next_stage_ = ScenarioConfig::PARK_AND_GO_ADJUST;
  }
  injector_->planning_context()
      ->mutable_planning_status()
      ->parkandgo.set__incheckstage(false);
  return Stage::FINISHED;
}

void ParkAndGoStageCheck::ADCInitStatus() {
  auto* park_and_go_status = &injector_->planning_context()
                                 ->mutable_planning_status()
                                 ->parkandgo;
  *park_and_go_status = apollo_msgs::msg::ApolloplanningParkAndGoStatus();
  park_and_go_status->adcinitposition.set__x(
      injector_->vehicle_state()->x());
  park_and_go_status->adcinitposition.set__y(
      injector_->vehicle_state()->y());
  park_and_go_status->adcinitposition.set__z(0.0);
  park_and_go_status->set__adcinitheading(
      injector_->vehicle_state()->heading());
  park_and_go_status->set__incheckstage(true);
}

}  // namespace park_and_go
}  // namespace scenario
}  // namespace planning
}  // namespace apollo
