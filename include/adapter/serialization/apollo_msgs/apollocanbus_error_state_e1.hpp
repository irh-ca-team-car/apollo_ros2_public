#pragma once
#include "apollo_msgs/msg/apollocanbus_error_state_e1.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusErrorStateE1 &msg) ;
    ApollocanbusErrorStateE1 from_json_ApollocanbusErrorStateE1 (nlohmann::json obj) ;
    template <>
    ApollocanbusErrorStateE1 from_json<ApollocanbusErrorStateE1>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusErrorStateE1 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusErrorStateE1 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusErrorStateE1 & dt);
}
