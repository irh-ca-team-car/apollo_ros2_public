#pragma once
#include "apollo_msgs/msg/apollocanbus_steering_cmd6d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringCmd6d &msg) ;
    ApollocanbusSteeringCmd6d from_json_ApollocanbusSteeringCmd6d (nlohmann::json obj) ;
    template <>
    ApollocanbusSteeringCmd6d from_json<ApollocanbusSteeringCmd6d>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringCmd6d &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringCmd6d & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringCmd6d & dt);
}
