#pragma once
#include "apollo_msgs/msg/apollocanbus_scu_bcs1306.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuBcs1306 &msg) ;
    ApollocanbusScuBcs1306 from_json_ApollocanbusScuBcs1306 (nlohmann::json obj) ;
    template <>
    ApollocanbusScuBcs1306 from_json<ApollocanbusScuBcs1306>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuBcs1306 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuBcs1306 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuBcs1306 & dt);
}
