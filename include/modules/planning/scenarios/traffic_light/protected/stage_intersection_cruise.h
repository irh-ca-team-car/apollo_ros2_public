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

#pragma once

#include <memory>

#include "modules/planning/scenarios/common/stage_intersection_cruise_impl.h"
#include "modules/planning/scenarios/stage.h"
#include "modules/planning/scenarios/traffic_light/protected/traffic_light_protected_scenario.h"

namespace apollo {
namespace planning {
namespace scenario {
namespace traffic_light {

struct TrafficLightProtectedContext;

class TrafficLightProtectedStageIntersectionCruise : public Stage {
 public:
  TrafficLightProtectedStageIntersectionCruise(
      const apollo_msgs::msg::ApolloplanningStageConfig& config,
      const std::shared_ptr<DependencyInjector>& injector)
      : Stage(config, injector) {}

 private:
  Stage::StageStatus Process(const common::TrajectoryPoint& planning_init_point,
                             Frame* frame) override;

  TrafficLightProtectedContext* GetContext() {
    return GetContextAs<TrafficLightProtectedContext>();
  }

  Stage::StageStatus FinishStage();

 private:
  apollo_msgs::msg::ApolloplanningScenarioTrafficLightProtectedConfig scenario_config_;
  StageIntersectionCruiseImpl stage_impl_;
};

}  // namespace traffic_light
}  // namespace scenario
}  // namespace planning
}  // namespace apollo
