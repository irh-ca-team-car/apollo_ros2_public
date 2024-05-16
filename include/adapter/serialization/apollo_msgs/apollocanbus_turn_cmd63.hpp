#pragma once
#include "apollo_msgs/msg/apollocanbus_turn_cmd63.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnCmd63 &msg) ;
    ApollocanbusTurnCmd63 from_json_ApollocanbusTurnCmd63 (nlohmann::json obj) ;
    template <>
    ApollocanbusTurnCmd63 from_json<ApollocanbusTurnCmd63>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnCmd63 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnCmd63 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnCmd63 & dt);
}
