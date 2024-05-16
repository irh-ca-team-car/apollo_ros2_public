#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_rpt204.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeRpt204 &msg) ;
    ApollocanbusBrakeRpt204 from_json_ApollocanbusBrakeRpt204 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeRpt204 from_json<ApollocanbusBrakeRpt204>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeRpt204 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeRpt204 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeRpt204 & dt);
}
