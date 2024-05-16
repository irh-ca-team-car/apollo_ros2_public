#pragma once
#include "apollo_msgs/msg/apolloplanning_ipopt_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningIpoptConfig &msg) ;
    ApolloplanningIpoptConfig from_json_ApolloplanningIpoptConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningIpoptConfig from_json<ApolloplanningIpoptConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningIpoptConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningIpoptConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningIpoptConfig & dt);
}
