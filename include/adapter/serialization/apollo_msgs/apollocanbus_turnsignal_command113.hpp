#pragma once
#include "apollo_msgs/msg/apollocanbus_turnsignal_command113.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnsignalCommand113 &msg) ;
    ApollocanbusTurnsignalCommand113 from_json_ApollocanbusTurnsignalCommand113 (nlohmann::json obj) ;
    template <>
    ApollocanbusTurnsignalCommand113 from_json<ApollocanbusTurnsignalCommand113>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnsignalCommand113 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnsignalCommand113 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnsignalCommand113 & dt);
}
