#pragma once
#include "apollo_msgs/msg/apollocanbus_throttle_command100.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusThrottleCommand100 &msg) ;
    ApollocanbusThrottleCommand100 from_json_ApollocanbusThrottleCommand100 (nlohmann::json obj) ;
    template <>
    ApollocanbusThrottleCommand100 from_json<ApollocanbusThrottleCommand100>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusThrottleCommand100 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusThrottleCommand100 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusThrottleCommand100 & dt);
}
