#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_motor_rpt375.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringMotorRpt375 &msg) ;
    ApollocanbusSteeringMotorRpt375 from_json_ApollocanbusSteeringMotorRpt375 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringMotorRpt375 from_json<ApollocanbusSteeringMotorRpt375>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringMotorRpt375 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringMotorRpt375 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringMotorRpt375 & dt);
}
