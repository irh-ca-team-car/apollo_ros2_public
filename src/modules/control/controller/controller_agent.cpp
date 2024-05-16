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

#include "modules/control/controller/controller_agent.h"

#include <utility>

#include "cyber/cyber.h"

#include "modules/control/common/control_gflags.h"
#include "modules/control/controller/lat_controller.h"
#include "modules/control/controller/lon_controller.h"
#include "modules/control/controller/mpc_controller.h"

namespace apollo {
namespace control {

using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::cyber::Clock;

void ControllerAgent::RegisterControllers(const apollo_msgs::msg::ApollocontrolControlConf *control_conf) {
  AINFO << "Only support MPC controller or Lat + Lon controllers as of now";
  for (auto active_controller : control_conf->activecontrollers) {
    switch (active_controller) {
      case ControlConf::MPC_CONTROLLER:
        controller_factory_.Register(
            ControlConf::MPC_CONTROLLER,
            []() -> Controller * {   ADEBUG << "PRODUCER_NPC" ; return new MPCController(); });
        break;
      case ControlConf::LAT_CONTROLLER:
        controller_factory_.Register(
            ControlConf::LAT_CONTROLLER,
            []() -> Controller * { ADEBUG << "lat_controller" ; 
            LatController* ptr = new LatController();
            ADEBUG << "lat_controller << " << ptr ; 
            return ptr;
             });
        break;
      case ControlConf::LON_CONTROLLER:
        controller_factory_.Register(
            ControlConf::LON_CONTROLLER,
            []() -> Controller * {  ADEBUG << "lon_controller" ; return new LonController(); });

        break;
      default:
        AERROR << "Unknown active controller type:" << active_controller;
    }
  }
}

Status ControllerAgent::InitializeConf(const apollo_msgs::msg::ApollocontrolControlConf *control_conf) {
  if (!control_conf) {
    AERROR << "control_conf is null";
    return Status(ErrorCode::CONTROL_INIT_ERROR, "Failed to load config");
  }
  control_conf_ = control_conf;
  for (auto controller_type : control_conf_->activecontrollers) {
    auto controller = controller_factory_.CreateObject(
        static_cast<ControlConf::ControllerType>(controller_type));
    if (controller) {
      for (size_t i =0; i<controller_list_.size();i++)
        {   ADEBUG << "Controller: " << controller_list_[i].get() ;} 
      controller_list_.push_back(std::move(controller));
    } else {
      AERROR << "Controller: " << controller_type << "is not supported";
      return Status(ErrorCode::CONTROL_INIT_ERROR,
                    "Invalid controller type:" + controller_type);
    } 
  }
  AINFO << "InitializeConf_OK";
  return  Status::OK();
}

Status ControllerAgent::Init(std::shared_ptr<DependencyInjector> injector,
                             const apollo_msgs::msg::ApollocontrolControlConf *control_conf)
{
  injector_ = injector;
  RegisterControllers(control_conf);
  ACHECK(InitializeConf(control_conf).ok()) << "Failed to initialize config.";
    for (size_t i =0; i<controller_list_.size();i++)
        {   ADEBUG << "Controller: " << controller_list_[i].get() ;} 
  for (auto &controller : controller_list_) {  
    if (controller == nullptr) { 
      AERROR << "Controller is null.";
      return Status(ErrorCode::CONTROL_INIT_ERROR, "Controller is null.");
    }
    ADEBUG << "Controller <" << controller->Name() << "> init started!";
    if (!controller->Init(injector, control_conf_).ok()) {   
      AERROR << "Controller <" << controller->Name() << "> init failed!";
      return Status(ErrorCode::CONTROL_INIT_ERROR,
                    "Failed to init Controller:" + controller->Name());
    }
    AINFO << "Controller <" << controller->Name() << "> init done!";
  }
  AINFO << "Init::OK";
  return Status::OK();
}

Status ControllerAgent::ComputeControlCommand(
    const localization::LocalizationEstimate *localization,
    const apollo_msgs::msg::ApollocanbusChassis *chassis, const apollo_msgs::msg::ApolloplanningADCTrajectory *trajectory,
    control::ControlCommand *cmd)
{
  for (auto &controller : controller_list_) {
    ADEBUG << "controller:" << controller->Name() << " processing ...";
    double start_timestamp = Clock::NowInSeconds();
    controller->ComputeControlCommand(localization, chassis, trajectory, cmd);
    double end_timestamp = Clock::NowInSeconds();
    const double time_diff_ms = (end_timestamp - start_timestamp) * 1000;

    ADEBUG << "controller: " << controller->Name()
           << " calculation time is: " << time_diff_ms << " ms.";
    cmd->latencystats.controllertimems.push_back(time_diff_ms);
  }
  return Status::OK();
}

Status ControllerAgent::Reset() {
  for (auto &controller : controller_list_) {
    ADEBUG << "controller:" << controller->Name() << " reset...";
    controller->Reset();
  }
  return Status::OK();
}

}  // namespace control
}  // namespace apollo
