#pragma once
#include "apollo_msgs/msg/apollocanbus_control_command115.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusControlCommand115 &msg) ;
    ApollocanbusControlCommand115 from_json_ApollocanbusControlCommand115 (nlohmann::json obj) ;
    template <>
    ApollocanbusControlCommand115 from_json<ApollocanbusControlCommand115>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusControlCommand115 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusControlCommand115 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusControlCommand115 & dt);
}
