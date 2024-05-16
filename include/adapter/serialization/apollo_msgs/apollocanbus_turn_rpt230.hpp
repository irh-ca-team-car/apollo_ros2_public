#pragma once
#include "apollo_msgs/msg/apollocanbus_turn_rpt230.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnRpt230 &msg) ;
    ApollocanbusTurnRpt230 from_json_ApollocanbusTurnRpt230 (nlohmann::json obj) ;
    template <>
    ApollocanbusTurnRpt230 from_json<ApollocanbusTurnRpt230>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnRpt230 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnRpt230 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnRpt230 & dt);
}
