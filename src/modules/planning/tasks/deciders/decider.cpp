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

#include "modules/planning/tasks/deciders/decider.h"

#include <memory>

namespace apollo {
namespace planning {

  Decider::Decider(const apollo_msgs::msg::ApolloplanningTaskConfig &config) : Task(config) {}

  Decider::Decider(const apollo_msgs::msg::ApolloplanningTaskConfig &config,
                   const std::shared_ptr<DependencyInjector> &injector)
      : Task(config, injector) {}

  apollo::common::Status Decider::Execute(
      Frame *frame, ReferenceLineInfo *reference_line_info)
  {
    Task::Execute(frame, reference_line_info);
    return Process(frame, reference_line_info);
}

apollo::common::Status Decider::Execute(Frame* frame) {
  Task::Execute(frame);
  return Process(frame);
}

}  // namespace planning
}  // namespace apollo
