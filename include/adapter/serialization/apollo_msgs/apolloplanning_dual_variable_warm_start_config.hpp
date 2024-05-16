#pragma once
#include "apollo_msgs/msg/apolloplanning_dual_variable_warm_start_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_ipopt_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_osqp_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDualVariableWarmStartConfig &msg) ;
    ApolloplanningDualVariableWarmStartConfig from_json_ApolloplanningDualVariableWarmStartConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningDualVariableWarmStartConfig from_json<ApolloplanningDualVariableWarmStartConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDualVariableWarmStartConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDualVariableWarmStartConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDualVariableWarmStartConfig & dt);
}
