#pragma once
#include "apollo_msgs/msg/apollocanbus_turn_cmd130.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnCmd130 &msg) ;
    ApollocanbusTurnCmd130 from_json_ApollocanbusTurnCmd130 (nlohmann::json obj) ;
    template <>
    ApollocanbusTurnCmd130 from_json<ApollocanbusTurnCmd130>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnCmd130 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnCmd130 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnCmd130 & dt);
}
