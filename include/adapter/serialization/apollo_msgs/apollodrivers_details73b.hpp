#pragma once
#include "apollo_msgs/msg/apollodrivers_details73b.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDetails73b &msg) ;
    ApollodriversDetails73b from_json_ApollodriversDetails73b (nlohmann::json obj) ;
    template <>
    ApollodriversDetails73b from_json<ApollodriversDetails73b>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDetails73b &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversDetails73b & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDetails73b & dt);
}
