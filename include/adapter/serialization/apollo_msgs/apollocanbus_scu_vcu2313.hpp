#pragma once
#include "apollo_msgs/msg/apollocanbus_scu_vcu2313.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuVcu2313 &msg) ;
    ApollocanbusScuVcu2313 from_json_ApollocanbusScuVcu2313 (nlohmann::json obj) ;
    template <>
    ApollocanbusScuVcu2313 from_json<ApollocanbusScuVcu2313>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuVcu2313 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuVcu2313 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuVcu2313 & dt);
}
