#pragma once
#include "apollo_msgs/msg/apollocanbus_accel_cmd100.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAccelCmd100 &msg) ;
    ApollocanbusAccelCmd100 from_json_ApollocanbusAccelCmd100 (nlohmann::json obj) ;
    template <>
    ApollocanbusAccelCmd100 from_json<ApollocanbusAccelCmd100>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAccelCmd100 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAccelCmd100 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAccelCmd100 & dt);
}
