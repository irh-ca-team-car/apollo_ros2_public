#pragma once
#include "apollo_msgs/msg/apollocanbus_light.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLight &msg) ;
    ApollocanbusLight from_json_ApollocanbusLight (nlohmann::json obj) ;
    template <>
    ApollocanbusLight from_json<ApollocanbusLight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLight &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLight & dt);
}
