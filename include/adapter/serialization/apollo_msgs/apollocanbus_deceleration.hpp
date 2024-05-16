#pragma once
#include "apollo_msgs/msg/apollocanbus_deceleration.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDeceleration &msg) ;
    ApollocanbusDeceleration from_json_ApollocanbusDeceleration (nlohmann::json obj) ;
    template <>
    ApollocanbusDeceleration from_json<ApollocanbusDeceleration>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDeceleration &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDeceleration & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDeceleration & dt);
}
