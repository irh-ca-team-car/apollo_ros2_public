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

#include "component/canbus.h"

#include "cyber/time/time.h"
#include "modules/canbus/common/canbus_gflags.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/util/util.h"

using apollo::common::ErrorCode;
using apollo::control::ControlCommand;
using apollo::cyber::Time;
using apollo::guardian::GuardianCommand;
using apollo_msgs::msg::ApollocanbusChassis;
using apollo_msgs::msg::ApollocanbusChassisDetail;

using std::placeholders::_1;

namespace apollo
{
    namespace canbus
    {

        std::string CanbusComponent::Name() const { return FLAGS_canbus_module_name; }

        CanbusComponent::CanbusComponent() : TimerComponent("CanbusComponent") {}

        bool CanbusComponent::Init()
        {
            apollo::common::gflags::init_common(this);
            apollo::common::gflags::init_common_adapter(this);
            // System gflags
            INIT_FLAG_string(canbus_node_name, "chassis", "The chassis module name in proto");
            INIT_FLAG_string(canbus_module_name, "canbus_component", "Module name");

            // Canbus gflags
            INIT_FLAG_double(chassis_freq, 100.0, "Chassis feedback timer frequency.");
            INIT_FLAG_int64(min_cmd_interval, 5, "Minimum control command interval in ms.");

            // chassis_detail message publish
            INIT_FLAG_bool(enable_chassis_detail_pub, false, "Chassis Detail message publish");

            // enable receiving guardian command
            // TODO(QiL) : depreciate this after test
            INIT_FLAG_bool(receive_guardian, false,
                           "Enable receiving guardian message on canbus side");

            INIT_FLAG_int32(guardian_cmd_pending_queue_size, 10,
                            "Max guardian cmd pending queue size");
            INIT_FLAG_int32(control_cmd_pending_queue_size, 10,
                            "Max control cmd pending queue size");

            // enable forward Ultrasonic AEB
            INIT_FLAG_bool(enable_aeb, true, "Enable forward Ultrasonic AEB");
            auto prefix = declare_parameter<std::string>("prefix", "car");

            RCLCPP_INFO(get_logger(), "--------------------");
            RCLCPP_INFO(get_logger(), "Parameters");
            RCLCPP_INFO(get_logger(), "--------------------");
            RCLCPP_INFO(get_logger(), "  prefix=%s", prefix.c_str());
            RCLCPP_INFO(get_logger(), "--------------------");

            auto can_topic = declare_parameter<std::string>("can_topic", prefix + CAN_TOPIC_DEFAULT);

            CAN_TOPIC = can_topic; // prefix + CAN_TOPIC_DEFAULT;
            CAR_ANGLE_FEEDBACK_TOPIC = prefix + CAR_ANGLE_FEEDBACK_TOPIC_DEFAULT;
            CAR_SPEED_FEEDBACK_TOPIC = prefix + CAR_SPEED_FEEDBACK_TOPIC_DEFAULT;

            RCLCPP_INFO(get_logger(), "Topics");
            RCLCPP_INFO(get_logger(), "--------------------");
            RCLCPP_INFO(get_logger(), "\tCANBUS   :%s", CAN_TOPIC.c_str());
            RCLCPP_INFO(get_logger(), "--------------------");

            sub_canbs = this->create_subscription<can_msgs::msg::Frame>(CAN_TOPIC, 10, std::bind(&CanbusComponent::callback_can, this, _1));
            sub_tf = this->create_subscription<LocalizationEstimate>("/apollo/localization/pose", 10, std::bind(&CanbusComponent::callback_tf, this, _1));
            //----------------------------

            cyber::ReaderConfig guardian_cmd_reader_config;
            guardian_cmd_reader_config.channel_name = FLAGS_guardian_topic;
            guardian_cmd_reader_config.pending_queue_size =
                FLAGS_guardian_cmd_pending_queue_size;

            cyber::ReaderConfig control_cmd_reader_config;
            control_cmd_reader_config.channel_name = FLAGS_control_command_topic;
            control_cmd_reader_config.pending_queue_size =
                FLAGS_control_cmd_pending_queue_size;

            chassis_writer_ = node_->CreateWriter<ApollocanbusChassis>(FLAGS_chassis_topic);

            chassis_detail_writer_ =
                node_->CreateWriter<ApollocanbusChassisDetail>(FLAGS_chassis_detail_topic);

            return true;
        }

        void CanbusComponent::callback_can(can_msgs::msg::Frame::SharedPtr msg)
        {
            kia_translator translator;
            translator.translate(*msg, chassis);
            translator.translate(*msg, chassis_detail);
        }
        void CanbusComponent::callback_tf(LocalizationEstimate::SharedPtr msg)
        {
            chassis.chassisgps.longitude = msg->pose.position.x;
            chassis.chassisgps.latitude = msg->pose.position.y;
            chassis.chassisgps.compassdirection = msg->pose.heading * 57.2957795; // To degrees
        }

        CanbusComponent::~CanbusComponent()
        {
            AINFO << "Cleanup Canbus component";
        }

        void CanbusComponent::PublishChassis()
        {
            // common::util::FillHeader(node_->Name(), &chassis);
            chassis_writer_->Write(chassis);
            // ADEBUG << chassis;
        }

        void CanbusComponent::PublishChassisDetail()
        {
            // message_manager_->GetSensorData(&chassis_detail);
            // ADEBUG << chassis_detail;
            chassis_detail_writer_->Write(chassis_detail);
        }

        bool CanbusComponent::Proc()
        {
            PublishChassis();
            if (FLAGS_enable_chassis_detail_pub)
            {
                PublishChassisDetail();
            }
            return true;
        }

    } // namespace canbus
} // namespace apollo

CYBER_REGISTER_COMPONENT(CanbusComponent)