#pragma once
#include "apollo_msgs/msg/apollodrivers_reference76a.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversReference76a &msg) ;
    ApollodriversReference76a from_json_ApollodriversReference76a (nlohmann::json obj) ;
    template <>
    ApollodriversReference76a from_json<ApollodriversReference76a>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversReference76a &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversReference76a & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversReference76a & dt);
}
