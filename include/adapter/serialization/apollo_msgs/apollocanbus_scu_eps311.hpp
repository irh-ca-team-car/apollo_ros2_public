#pragma once
#include "apollo_msgs/msg/apollocanbus_scu_eps311.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuEps311 &msg) ;
    ApollocanbusScuEps311 from_json_ApollocanbusScuEps311 (nlohmann::json obj) ;
    template <>
    ApollocanbusScuEps311 from_json<ApollocanbusScuEps311>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuEps311 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuEps311 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuEps311 & dt);
}
