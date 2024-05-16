#pragma once
#include "apollo_msgs/msg/apollocanbus_turnsignal_status513.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnsignalStatus513 &msg) ;
    ApollocanbusTurnsignalStatus513 from_json_ApollocanbusTurnsignalStatus513 (nlohmann::json obj) ;
    template <>
    ApollocanbusTurnsignalStatus513 from_json<ApollocanbusTurnsignalStatus513>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnsignalStatus513 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnsignalStatus513 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnsignalStatus513 & dt);
}
