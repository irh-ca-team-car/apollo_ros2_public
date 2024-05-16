#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_motor_rpt2405.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringMotorRpt2405 &msg) ;
    ApollocanbusSteeringMotorRpt2405 from_json_ApollocanbusSteeringMotorRpt2405 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringMotorRpt2405 from_json<ApollocanbusSteeringMotorRpt2405>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringMotorRpt2405 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringMotorRpt2405 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringMotorRpt2405 & dt);
}
