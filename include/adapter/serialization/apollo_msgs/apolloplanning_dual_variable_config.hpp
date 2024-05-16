#pragma once
#include "apollo_msgs/msg/apolloplanning_dual_variable_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_ipopt_solver_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDualVariableConfig &msg) ;
    ApolloplanningDualVariableConfig from_json_ApolloplanningDualVariableConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningDualVariableConfig from_json<ApolloplanningDualVariableConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDualVariableConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDualVariableConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDualVariableConfig & dt);
}
