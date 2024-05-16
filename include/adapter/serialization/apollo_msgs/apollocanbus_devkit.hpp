#pragma once
#include "apollo_msgs/msg/apollocanbus_devkit.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_command100.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_command101.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_command102.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_command103.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_park_command104.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_report500.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_report501.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_report502.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_report503.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_park_report504.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_report505.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wheelspeed_report506.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor1507.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor2508.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor3509.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor4510.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor5511.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_bms_report512.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDevkit &msg) ;
    ApollocanbusDevkit from_json_ApollocanbusDevkit (nlohmann::json obj) ;
    template <>
    ApollocanbusDevkit from_json<ApollocanbusDevkit>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDevkit &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDevkit & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDevkit & dt);
}
