#pragma once
#include "apollo_msgs/msg/apollodrivers_ldw_lane.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_lane_boundary.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwLane &msg) ;
    ApollodriversLdwLane from_json_ApollodriversLdwLane (nlohmann::json obj) ;
    template <>
    ApollodriversLdwLane from_json<ApollodriversLdwLane>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwLane &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwLane & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwLane & dt);
}
