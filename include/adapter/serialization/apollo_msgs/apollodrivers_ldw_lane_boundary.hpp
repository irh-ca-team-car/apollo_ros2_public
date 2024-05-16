#pragma once
#include "apollo_msgs/msg/apollodrivers_ldw_lane_boundary.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwLaneBoundary &msg) ;
    ApollodriversLdwLaneBoundary from_json_ApollodriversLdwLaneBoundary (nlohmann::json obj) ;
    template <>
    ApollodriversLdwLaneBoundary from_json<ApollodriversLdwLaneBoundary>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwLaneBoundary &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwLaneBoundary & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwLaneBoundary & dt);
}
