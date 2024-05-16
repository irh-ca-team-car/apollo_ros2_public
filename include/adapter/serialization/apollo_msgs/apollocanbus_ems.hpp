#pragma once
#include "apollo_msgs/msg/apollocanbus_ems.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEms &msg) ;
    ApollocanbusEms from_json_ApollocanbusEms (nlohmann::json obj) ;
    template <>
    ApollocanbusEms from_json<ApollocanbusEms>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEms &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEms & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEms & dt);
}
