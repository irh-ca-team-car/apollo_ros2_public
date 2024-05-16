#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_motor_rpt173.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringMotorRpt173 &msg) ;
    ApollocanbusSteeringMotorRpt173 from_json_ApollocanbusSteeringMotorRpt173 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringMotorRpt173 from_json<ApollocanbusSteeringMotorRpt173>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringMotorRpt173 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringMotorRpt173 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringMotorRpt173 & dt);
}
