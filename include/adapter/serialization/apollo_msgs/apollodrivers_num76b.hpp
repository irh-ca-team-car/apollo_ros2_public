#pragma once
#include "apollo_msgs/msg/apollodrivers_num76b.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversNum76b &msg) ;
    ApollodriversNum76b from_json_ApollodriversNum76b (nlohmann::json obj) ;
    template <>
    ApollodriversNum76b from_json<ApollodriversNum76b>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversNum76b &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversNum76b & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversNum76b & dt);
}
