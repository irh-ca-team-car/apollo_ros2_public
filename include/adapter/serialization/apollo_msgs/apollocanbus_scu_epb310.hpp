#pragma once
#include "apollo_msgs/msg/apollocanbus_scu_epb310.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuEpb310 &msg) ;
    ApollocanbusScuEpb310 from_json_ApollocanbusScuEpb310 (nlohmann::json obj) ;
    template <>
    ApollocanbusScuEpb310 from_json<ApollocanbusScuEpb310>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuEpb310 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuEpb310 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuEpb310 & dt);
}
