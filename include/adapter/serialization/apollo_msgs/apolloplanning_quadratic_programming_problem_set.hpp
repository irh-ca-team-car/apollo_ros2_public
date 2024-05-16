#pragma once
#include "apollo_msgs/msg/apolloplanning_quadratic_programming_problem_set.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_quadratic_programming_problem.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningQuadraticProgrammingProblemSet &msg) ;
    ApolloplanningQuadraticProgrammingProblemSet from_json_ApolloplanningQuadraticProgrammingProblemSet (nlohmann::json obj) ;
    template <>
    ApolloplanningQuadraticProgrammingProblemSet from_json<ApolloplanningQuadraticProgrammingProblemSet>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningQuadraticProgrammingProblemSet &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningQuadraticProgrammingProblemSet & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningQuadraticProgrammingProblemSet & dt);
}
