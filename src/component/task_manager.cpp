/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
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
#include "component/task_manager.h"
 
#include "modules/task_manager/proto/task_manager_config.pb.h"
#include "modules/task_manager/common/task_manager_gflags.h"
#include "cyber/cyber.h"
 
 extern std::shared_ptr<apollo::task_manager::TaskManagerComponent> node__;

namespace apollo {
namespace task_manager {
 
using apollo::cyber::ComponentBase;
using apollo::localization::LocalizationEstimate;
using apollo::routing::RoutingRequest;
 
 
bool TaskManagerComponent::Init() {

    INIT_FLAG_double(threshold_for_destination_check, 10, "threshold_for_destination_check");
  TaskManagerConfig task_manager_conf;
  task_manager_conf.topicconfig.routingrequesttopic=declare_parameter<std::string>("routing_request_topic","/apollo/routing_request");
  task_manager_conf.topicconfig.localizationposetopic=declare_parameter<std::string>("localization_pose_topic","/apollo/localization/pose");
 
  task_manager_reader_ = node_->CreateReader<apollo_msgs::msg::ApollotaskManagerTask>( "/apollo/task_manager",std::bind(&TaskManagerComponent::Proc, this, std::placeholders::_1));
  
  localization_reader_ = node_->CreateReader<LocalizationEstimate>(
      task_manager_conf.topicconfig.localizationposetopic,
      [this](const std::shared_ptr<apollo_msgs::msg::ApollolocalizationLocalizationEstimate>& localization) {
        ADEBUG << "Received localization data: run localization callback.";
        localization_ = (*localization);
      });


  request_writer_ = node_->CreateWriter<RoutingRequest>(
  task_manager_conf.topicconfig.routingrequesttopic
);
  return true;
 
 }
 
bool TaskManagerComponent::Proc(const std::shared_ptr<Task>& task) {
  task_name_ = task->taskname;
  if (task->tasktype != CYCLE_ROUTING) {
    AINFO << "Task type is not cycle_routing.";
    return false;
  }

  cycle_routing_manager_ = std::make_shared<CycleRoutingManager>();
  cycle_routing_manager_->Init(task->cycleroutingtask);
  routing_request_ = task->cycleroutingtask.routingrequest;
  rclcpp::Rate rate(1.0);
 
  while (rclcpp::ok() || cycle_routing_manager_->GetCycle() > 0) {
    
    if (cycle_routing_manager_->GetNewRouting(localization_.pose,
                                             &routing_request_)) {
     node_->FillHeader(node_->get_name(), routing_request_);
     request_writer_->Write(routing_request_);
     AINFO << "[TaskManagerComponent]Reach begin/end point: "
           << "routing manager send a routing request. ";
    }
    
    rate.sleep();
  }
  return true;
}
}  // namespace task_manager
}  // namespace apollo
CYBER_REGISTER_COMPONENT(TaskManagerComponent)