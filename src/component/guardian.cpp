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
#include "component/guardian.h"

#include "cyber/common/log.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/util/message_util.h"

using Time = ::apollo::cyber::Time;

namespace apollo
{
  namespace guardian
  {

    using apollo_msgs::msg::ApollocanbusChassis;
    using apollo_msgs::msg::ApollocontrolControlCommand;
    using apollo_msgs::msg::ApollomonitorSystemStatus;

    bool GuardianComponent::Init()
    {
      guardian_conf_.guardianenable = declare_parameter<bool>("guardian_enable", true);
      apollo::common::gflags::init_common_adapter(this);

      chassis_reader_ = node_->CreateReader<apollo_msgs::msg::ApollocanbusChassis>(
          FLAGS_chassis_topic, [this](const std::shared_ptr<apollo_msgs::msg::ApollocanbusChassis> &chassis)
          {
            ADEBUG << "Received chassis data: run chassis callback.";
            chassis_ = *chassis;
          });

      control_cmd_reader_ = node_->CreateReader<apollo_msgs::msg::ApollocontrolControlCommand>(
          FLAGS_control_command_topic,
          [this](const std::shared_ptr<apollo_msgs::msg::ApollocontrolControlCommand> &cmd)
          {
            ADEBUG << "Received control data: run control callback.";
            control_cmd_ = *cmd;
          });

      system_status_reader_ = node_->CreateReader<apollo_msgs::msg::ApollomonitorSystemStatus>(
          FLAGS_system_status_topic,
          [this](const std::shared_ptr<apollo_msgs::msg::ApollomonitorSystemStatus> &status)
          {
            ADEBUG << "Received system status data: run system status callback.";
            last_status_received_s_ = Time::Now().ToSecond();
            system_status_ = *status;
          });

      guardian_writer_ = node_->CreateWriter<GuardianCommand>(FLAGS_guardian_topic);

      return true;
    }
    long GuardianComponent::IntervalMilliseconds() { return 10; }
    bool GuardianComponent::Proc()
    {
      PassThroughControlCommand();

      node_->FillHeader(node_->get_name(), guardian_cmd_);
      guardian_writer_->Write(guardian_cmd_);
      return true;
    }

    void GuardianComponent::PassThroughControlCommand()
    {
      guardian_cmd_.controlcommand = control_cmd_;
    }

    void GuardianComponent::TriggerSafetyMode()
    {
      AINFO << "Safety state triggered, with system safety mode trigger time : "
            << system_status_.safetymodetriggertime;
      bool sensor_malfunction = false, obstacle_detected = false;
      if (!chassis_.surround.sonarenabled ||
          chassis_.surround.sonarfault)
      {
        //AINFO << "Ultrasonic sensor not enabled for faulted, will do emergency "
        //         "stop!";
        //sensor_malfunction = true;
      }
      else
      {
        // TODO(QiL) : Load for config
        for (size_t i = 0; i < chassis_.surround.sonarrange.size(); ++i)
        {
          if ((chassis_.surround.sonarrange[i] > 0.0 &&
               chassis_.surround.sonarrange[i] < 2.5) ||
              chassis_.surround.sonarrange[i] > 30)
          {
            AINFO << "Object detected or ultrasonic sensor fault output, will do "
                     "emergency stop!";
            obstacle_detected = true;
          }
        }
      }

      guardian_cmd_.controlcommand.throttle = 0.0;
      guardian_cmd_.controlcommand.steeringtarget = 0.0;
      guardian_cmd_.controlcommand.steeringrate = 25.0;
      guardian_cmd_.controlcommand.isinsafemode = true;

      // TODO(QiL) : Remove this one once hardware re-alignment is done.
      sensor_malfunction = false;
      obstacle_detected = false;
      //AINFO << "Temporarily ignore the ultrasonic sensor output during hardware "
      //         "re-alignment!";

      if (system_status_.requireemergencystop || sensor_malfunction ||
          obstacle_detected)
      {
        AINFO << "Emergency stop triggered! with system status from monitor as : "
              << system_status_.requireemergencystop;
        guardian_cmd_.controlcommand.brake =
            guardian_conf_.guardiancmdemergencystoppercentage;
      }
      else
      {
        AINFO << "Soft stop triggered! with system status from monitor as : "
              << system_status_.requireemergencystop;
        guardian_cmd_.controlcommand.brake =
            guardian_conf_.guardiancmdsoftstoppercentage;
      }
    }

  } // namespace guardian
} // namespace apollo
CYBER_REGISTER_COMPONENT(GuardianComponent)