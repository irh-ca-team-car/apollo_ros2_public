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

#include "modules/planning/tasks/optimizers/path_optimizer.h"

#include <memory>

#include "modules/planning/common/planning_gflags.h"

namespace apollo {
namespace planning {

using apollo::common::Status;

PathOptimizer::PathOptimizer(const apollo_msgs::msg::ApolloplanningTaskConfig &config) : Task(config) {}

PathOptimizer::PathOptimizer(
    const apollo_msgs::msg::ApolloplanningTaskConfig& config,
    const std::shared_ptr<DependencyInjector>& injector)
    : Task(config, injector) {}

Status PathOptimizer::Execute(Frame* frame,
                              ReferenceLineInfo* const reference_line_info) {
  Task::Execute(frame, reference_line_info);
  auto ret = Process(
      reference_line_info->speed_data(), reference_line_info->reference_line(),
      frame->PlanningStartPoint(), reference_line_info->path_reusable(),
      reference_line_info->mutable_path_data());
  RecordDebugInfo(reference_line_info->path_data());
  if (ret != Status::OK()) {
    reference_line_info->SetDrivable(false);
    AERROR << "Reference Line " << reference_line_info->Lanes().Id()
           << " is not drivable after " << Name();
  }
  return ret;
}

void PathOptimizer::RecordDebugInfo(const PathData& path_data) {
  const auto& path_points = path_data.discretized_path();
  auto* ptr_optimized_path = &reference_line_info_->mutable_debug()->planningdata.path.emplace_back();
  ptr_optimized_path->set__name(Name());
  ptr_optimized_path->pathpoint.clear();
  for (auto i = path_points.begin(); i < path_points.end();i++)
  {
    ptr_optimized_path->pathpoint.push_back(*i);
  }
}

}  // namespace planning
}  // namespace apollo
