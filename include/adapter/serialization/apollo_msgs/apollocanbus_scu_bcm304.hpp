#pragma once
#include "apollo_msgs/msg/apollocanbus_scu_bcm304.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuBcm304 &msg) ;
    ApollocanbusScuBcm304 from_json_ApollocanbusScuBcm304 (nlohmann::json obj) ;
    template <>
    ApollocanbusScuBcm304 from_json<ApollocanbusScuBcm304>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuBcm304 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuBcm304 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuBcm304 & dt);
}
