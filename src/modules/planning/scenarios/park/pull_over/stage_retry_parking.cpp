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

#include "modules/planning/scenarios/park/pull_over/stage_retry_parking.h"

#include <memory>

#include "cyber/common/log.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/planning/common/frame.h"
#include "modules/planning/common/planning_context.h"
#include "modules/planning/scenarios/util/util.h"

namespace apollo {
namespace planning {
namespace scenario {
namespace pull_over {

using apollo::common::TrajectoryPoint;

PullOverStageRetryParking::PullOverStageRetryParking(
    const apollo_msgs::msg::ApolloplanningStageConfig& config,
    const std::shared_ptr<DependencyInjector>& injector)
    : Stage(config, injector) {}

Stage::StageStatus PullOverStageRetryParking::Process(
    const TrajectoryPoint& planning_init_point, Frame* frame) {
  UNUSED(planning_init_point);
  ADEBUG << "stage: RetryParking";
  CHECK_NOTNULL(frame);

  scenario_config_=(GetContext()->scenario_config);

  // Open space planning doesn't use planning_init_point from upstream because
  // of different stitching strategy
  frame->mutable_open_space_info()->set_is_on_open_space_trajectory(true);
  bool plan_ok = ExecuteTaskOnOpenSpace(frame);
  if (!plan_ok) {
    AERROR << "PullOverStageRetryParking planning error";
    return StageStatus::ERROR;
  }

  // set debug info in planning_data
  const auto& pull_over_status =
      injector_->planning_context()->planning_status().pullover;
  auto* pull_over_debug = &frame->mutable_open_space_info()
                              ->mutable_debug()
                              ->planningdata.pullover;
  pull_over_debug->position=(pull_over_status.position);
  pull_over_debug->set__theta(pull_over_status.theta);
  pull_over_debug->set__lengthfront(pull_over_status.lengthfront);
  pull_over_debug->set__lengthback(pull_over_status.lengthback);
  pull_over_debug->set__widthleft(pull_over_status.widthleft);
  pull_over_debug->set__widthright(pull_over_status.widthright);
  frame->mutable_open_space_info()->sync_debug_instance();

  if (CheckADCPullOverOpenSpace()) {
    return FinishStage();
  }

  return StageStatus::RUNNING;
}

Stage::StageStatus PullOverStageRetryParking::FinishStage() {
  return FinishScenario();
}

bool PullOverStageRetryParking::CheckADCPullOverOpenSpace() {
  const auto& pull_over_status =
      injector_->planning_context()->planning_status().pullover;
  if (pull_over_status.position == apollo::common::PointENU()) {
    ADEBUG << "pull_over status not set properly: "
           << pull_over_status;
    return false;
  }

  const common::math::Vec2d adc_position = {injector_->vehicle_state()->x(),
                                            injector_->vehicle_state()->y()};
  const common::math::Vec2d target_position = {pull_over_status.position.x,
                                               pull_over_status.position.y};

  const double distance_diff = adc_position.DistanceTo(target_position);
  const double theta_diff = std::fabs(common::math::NormalizeAngle(
      pull_over_status.theta - injector_->vehicle_state()->heading()));
  ADEBUG << "distance_diff[" << distance_diff << "] theta_diff[" << theta_diff
         << "]";
  // check distance/theta diff
  return (distance_diff <= scenario_config_.maxdistanceerrortoendpoint &&
          theta_diff <= scenario_config_.maxthetaerrortoendpoint);
}

}  // namespace pull_over
}  // namespace scenario
}  // namespace planning
}  // namespace apollo
