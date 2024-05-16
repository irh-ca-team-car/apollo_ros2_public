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
 
#pragma once
 
#include <memory>
#include <string>
 
#include "cyber/cyber.h"
#include "cyber/component.h"
#include "modules/task_manager/cycle_routing_manager.h"
 
namespace apollo {
namespace task_manager {
 
using apollo::localization::LocalizationEstimate;
 
class TaskManagerComponent final
 : public cyber::Component
  {
 public:
  TaskManagerComponent() : Component("TaskManagerComponent"){} ;;
  ~TaskManagerComponent() = default;
struct  
  {
    std::string routingrequesttopic ;
    std::string localizationposetopic ;
  }topicconfig;
 public:
  bool Init() 

  ;
  bool Proc(const std::shared_ptr<task_manager::Task>& task) 

  ;
 
 private:
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApollolocalizationLocalizationEstimate>> localization_reader_;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApollotaskManagerTask>> task_manager_reader_;
  std::shared_ptr<cyber::Writer<routing::RoutingRequest>> request_writer_;
  std::shared_ptr<CycleRoutingManager> cycle_routing_manager_;
  routing::RoutingRequest routing_request_;
  apollo_msgs::msg::ApollolocalizationLocalizationEstimate localization_;
  //std::mutex mutex_;
  std::string task_name_;
};
 
 
 
}  // namespace task_manager
}  // namespace apollo