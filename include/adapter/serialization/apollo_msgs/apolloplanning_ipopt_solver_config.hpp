#pragma once
#include "apollo_msgs/msg/apolloplanning_ipopt_solver_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningIpoptSolverConfig &msg) ;
    ApolloplanningIpoptSolverConfig from_json_ApolloplanningIpoptSolverConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningIpoptSolverConfig from_json<ApolloplanningIpoptSolverConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningIpoptSolverConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningIpoptSolverConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningIpoptSolverConfig & dt);
}
