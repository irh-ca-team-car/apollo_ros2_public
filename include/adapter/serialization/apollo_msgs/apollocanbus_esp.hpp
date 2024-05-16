#pragma once
#include "apollo_msgs/msg/apollocanbus_esp.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEsp &msg) ;
    ApollocanbusEsp from_json_ApollocanbusEsp (nlohmann::json obj) ;
    template <>
    ApollocanbusEsp from_json<ApollocanbusEsp>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEsp &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEsp & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEsp & dt);
}
