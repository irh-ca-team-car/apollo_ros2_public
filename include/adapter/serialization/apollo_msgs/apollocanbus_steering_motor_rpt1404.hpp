#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_motor_rpt1404.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringMotorRpt1404 &msg) ;
    ApollocanbusSteeringMotorRpt1404 from_json_ApollocanbusSteeringMotorRpt1404 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringMotorRpt1404 from_json<ApollocanbusSteeringMotorRpt1404>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringMotorRpt1404 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringMotorRpt1404 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringMotorRpt1404 & dt);
}
