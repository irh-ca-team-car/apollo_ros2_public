#pragma once
#include "apollo_msgs/msg/apollodrivers_lka768.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLka768 &msg) ;
    ApollodriversLka768 from_json_ApollodriversLka768 (nlohmann::json obj) ;
    template <>
    ApollodriversLka768 from_json<ApollodriversLka768>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLka768 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversLka768 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLka768 & dt);
}
