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
 */

#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "cyber/common/macros.h"
#include "cyber/cyber.h"

#include "modules/canbus/proto/chassis_detail.pb.h"
#include "modules/drivers/canbus/proto/can_card_parameter.pb.h"
#include "modules/guardian/proto/guardian.pb.h"

#include "modules/canbus/vehicle/vehicle_controller.h"
#include "modules/common/status/status.h"
#include "modules/control/proto/control_cmd.pb.h"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/bool.hpp"
#include "can_msgs/msg/frame.hpp"
#include "modules/canbus/kia/translator.hpp"
#include "tf2_msgs/msg/tf_message.hpp"
#include "apollo_msgs/msg/apollolocalization_localization_estimate.hpp"

typedef apollo_msgs::msg::ApollolocalizationLocalizationEstimate LocalizationEstimate;

#define CAN_TOPIC_DEFAULT "/can0"
#define CAR_ENABLED_TOPIC_DEFAULT "/enabled"
#define CAR_BRAKE_TOPIC_DEFAULT "/brake"
#define CAR_THROTTLE_TOPIC_DEFAULT "/throttle"
#define CAR_STEERING_TORQUE_TOPIC_DEFAULT "/steering/torque"
#define CAR_SPEED_FEEDBACK_TOPIC_DEFAULT "/speed/actual"
#define CAR_ANGLE_FEEDBACK_TOPIC_DEFAULT "/steering/angle/actual"

/**
 * @namespace apollo::canbus
 * @brief apollo::canbus
 */
namespace apollo
{
    namespace canbus
    {

        /**
 * @class Canbus
 *
 * @brief canbus module main class.
 * It processes the control data to send protocol messages to can card.
 */
        class CanbusComponent final : public apollo::cyber::TimerComponent
        {
        public:
            CanbusComponent();
            ~CanbusComponent();
            /**
   * @brief obtain module name
   * @return module name
   */
            std::string Name() const;

        private:
            /**
   * @brief module initialization function
   * @return initialization status
   */
            bool Init() override;

            /**
   * @brief module on_time function
   */
            bool Proc() override;

            /**
   * @brief module cleanup function
   */
            void PublishChassis();
            void PublishChassisDetail();

            long IntervalMilliseconds() { return 10; }

            void callback_can(can_msgs::msg::Frame::SharedPtr msg);
            void callback_tf(LocalizationEstimate::SharedPtr msg);

            std::shared_ptr<cyber::Reader<apollo::control::ControlCommand>> control_command_reader_;
            int64_t last_timestamp_ = 0;

            apollo_msgs::msg::ApollocanbusChassis chassis;
            apollo_msgs::msg::ApollocanbusChassisDetail chassis_detail;
            std::shared_ptr<cyber::Writer<apollo_msgs::msg::ApollocanbusChassis>> chassis_writer_;
            std::shared_ptr<cyber::Writer<apollo_msgs::msg::ApollocanbusChassisDetail>> chassis_detail_writer_;

            std::string CAN_TOPIC;
            std::string CAR_SPEED_FEEDBACK_TOPIC;
            std::string CAR_ANGLE_FEEDBACK_TOPIC;
            geometry_msgs::msg::TransformStamped previous;

            rclcpp::Subscription<can_msgs::msg::Frame>::SharedPtr sub_canbs;
            rclcpp::Subscription<LocalizationEstimate>::SharedPtr sub_tf;
        };

        

    } // namespace canbus
} // namespace apollo