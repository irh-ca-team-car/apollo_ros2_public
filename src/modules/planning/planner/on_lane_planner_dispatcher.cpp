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

#include "modules/planning/planner/on_lane_planner_dispatcher.h"

#include <memory>

#include "modules/planning/proto/planning_config.pb.h"

namespace apollo {
namespace planning {

std::unique_ptr<Planner> OnLanePlannerDispatcher::DispatchPlanner(
    const apollo_msgs::msg::ApolloplanningPlanningConfig& planning_config,
    const std::shared_ptr<DependencyInjector>& injector) {
  return planner_factory_.CreateObject(
      (apollo::planning::PlannerType)planning_config.planningconfig.standardplanningconfig.plannertype[0], injector);
}

}  // namespace planning
}  // namespace apollo