#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_motor_rpt3406.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringMotorRpt3406 &msg) ;
    ApollocanbusSteeringMotorRpt3406 from_json_ApollocanbusSteeringMotorRpt3406 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringMotorRpt3406 from_json<ApollocanbusSteeringMotorRpt3406>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringMotorRpt3406 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringMotorRpt3406 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringMotorRpt3406 & dt);
}
