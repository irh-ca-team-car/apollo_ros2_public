#pragma once
#include "apollo_msgs/msg/apollocanbus_turn_rpt64.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnRpt64 &msg) ;
    ApollocanbusTurnRpt64 from_json_ApollocanbusTurnRpt64 (nlohmann::json obj) ;
    template <>
    ApollocanbusTurnRpt64 from_json<ApollocanbusTurnRpt64>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnRpt64 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnRpt64 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnRpt64 & dt);
}
