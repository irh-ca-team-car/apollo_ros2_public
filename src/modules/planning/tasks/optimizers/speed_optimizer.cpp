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

#include "modules/planning/tasks/optimizers/speed_optimizer.h"

#include "modules/planning/common/planning_gflags.h"
#include "modules/planning/common/speed_limit.h"

namespace apollo {
namespace planning {

using apollo::common::Status;
using apollo::planningInternal::STGraphDebug;

SpeedOptimizer::SpeedOptimizer(const apollo_msgs::msg::ApolloplanningTaskConfig& config) : Task(config) {}

Status SpeedOptimizer::Execute(Frame* frame,
                               ReferenceLineInfo* reference_line_info) {
  Task::Execute(frame, reference_line_info);

  auto ret =
      Process(reference_line_info->path_data(), frame->PlanningStartPoint(),
              reference_line_info->mutable_speed_data());

  RecordDebugInfo(reference_line_info->speed_data());
  return ret;
}

void SpeedOptimizer::RecordDebugInfo(const SpeedData& speed_data) {
  auto* debug = reference_line_info_->mutable_debug();
  auto ptr_speed_plan = &debug->planningdata.speedplan.emplace_back();
  ptr_speed_plan->set__name(Name());
  ptr_speed_plan->speedpoint.clear();
  for(auto i = speed_data.begin();i<speed_data.end();i++)
    ptr_speed_plan->speedpoint.push_back(*i);
  
}

void SpeedOptimizer::RecordDebugInfo(const SpeedData &speed_data,
                                     apollo_msgs::msg::ApolloplanningInternalSTGraphDebug *st_graph_debug)
{
  if (!FLAGS_enable_record_debug || !st_graph_debug) {
    ADEBUG << "Skip record debug info";
    return;
  }
  st_graph_debug->set__name(Name());
  st_graph_debug->speedprofile.clear();
  
  for(auto i=speed_data.begin();i< speed_data.end();i++)
    st_graph_debug->speedprofile.push_back(*i);
}

}  // namespace planning
}  // namespace apollo
