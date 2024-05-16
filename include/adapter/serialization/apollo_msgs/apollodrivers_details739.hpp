#pragma once
#include "apollo_msgs/msg/apollodrivers_details739.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDetails739 &msg) ;
    ApollodriversDetails739 from_json_ApollodriversDetails739 (nlohmann::json obj) ;
    template <>
    ApollodriversDetails739 from_json<ApollodriversDetails739>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDetails739 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversDetails739 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDetails739 & dt);
}
