#pragma once
#include "apollo_msgs/msg/apollocanbus_throttle_status510.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusThrottleStatus510 &msg) ;
    ApollocanbusThrottleStatus510 from_json_ApollocanbusThrottleStatus510 (nlohmann::json obj) ;
    template <>
    ApollocanbusThrottleStatus510 from_json<ApollocanbusThrottleStatus510>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusThrottleStatus510 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusThrottleStatus510 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusThrottleStatus510 & dt);
}
