#pragma once
#include "apollo_msgs/msg/apollocanbus_scu_bcs2307.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuBcs2307 &msg) ;
    ApollocanbusScuBcs2307 from_json_ApollocanbusScuBcs2307 (nlohmann::json obj) ;
    template <>
    ApollocanbusScuBcs2307 from_json<ApollocanbusScuBcs2307>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuBcs2307 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuBcs2307 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuBcs2307 & dt);
}
