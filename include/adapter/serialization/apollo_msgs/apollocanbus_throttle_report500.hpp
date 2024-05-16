#pragma once
#include "apollo_msgs/msg/apollocanbus_throttle_report500.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusThrottleReport500 &msg) ;
    ApollocanbusThrottleReport500 from_json_ApollocanbusThrottleReport500 (nlohmann::json obj) ;
    template <>
    ApollocanbusThrottleReport500 from_json<ApollocanbusThrottleReport500>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusThrottleReport500 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusThrottleReport500 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusThrottleReport500 & dt);
}
