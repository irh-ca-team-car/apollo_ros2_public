#pragma once
#include "apollo_msgs/msg/apollocanbus_turn_aux_rpt330.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnAuxRpt330 &msg) ;
    ApollocanbusTurnAuxRpt330 from_json_ApollocanbusTurnAuxRpt330 (nlohmann::json obj) ;
    template <>
    ApollocanbusTurnAuxRpt330 from_json<ApollocanbusTurnAuxRpt330>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnAuxRpt330 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnAuxRpt330 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnAuxRpt330 & dt);
}
