#pragma once
#include "apollo_msgs/msg/apolloplanning_quadratic_programming_problem.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_qp_matrix.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningQuadraticProgrammingProblem &msg) ;
    ApolloplanningQuadraticProgrammingProblem from_json_ApolloplanningQuadraticProgrammingProblem (nlohmann::json obj) ;
    template <>
    ApolloplanningQuadraticProgrammingProblem from_json<ApolloplanningQuadraticProgrammingProblem>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningQuadraticProgrammingProblem &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningQuadraticProgrammingProblem & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningQuadraticProgrammingProblem & dt);
}
