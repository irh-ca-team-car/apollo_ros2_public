#pragma once
#include "apollo_msgs/msg/apollocanbus_scu_vcu1312.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuVcu1312 &msg) ;
    ApollocanbusScuVcu1312 from_json_ApollocanbusScuVcu1312 (nlohmann::json obj) ;
    template <>
    ApollocanbusScuVcu1312 from_json<ApollocanbusScuVcu1312>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuVcu1312 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuVcu1312 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuVcu1312 & dt);
}
