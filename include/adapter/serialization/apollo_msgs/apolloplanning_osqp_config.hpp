#pragma once
#include "apollo_msgs/msg/apolloplanning_osqp_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOSQPConfig &msg) ;
    ApolloplanningOSQPConfig from_json_ApolloplanningOSQPConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningOSQPConfig from_json<ApolloplanningOSQPConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOSQPConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOSQPConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOSQPConfig & dt);
}
