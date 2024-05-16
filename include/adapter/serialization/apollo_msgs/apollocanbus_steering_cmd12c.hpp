#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_cmd12c.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringCmd12c &msg) ;
    ApollocanbusSteeringCmd12c from_json_ApollocanbusSteeringCmd12c (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringCmd12c from_json<ApollocanbusSteeringCmd12c>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringCmd12c &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringCmd12c & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringCmd12c & dt);
}
