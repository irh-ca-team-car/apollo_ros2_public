#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_control_a2.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringControlA2 &msg) ;
    ApollocanbusSteeringControlA2 from_json_ApollocanbusSteeringControlA2 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringControlA2 from_json<ApollocanbusSteeringControlA2>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringControlA2 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringControlA2 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringControlA2 & dt);
}
