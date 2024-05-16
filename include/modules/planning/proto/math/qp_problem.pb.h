#pragma once
#include "apollo_msgs/msg/apolloplanning_quadratic_programming_problem.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_quadratic_programming_problem.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningQuadraticProgrammingProblem QuadraticProgrammingProblem;
}
#include "apollo_msgs/msg/apolloplanning_qp_matrix.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_qp_matrix.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningQPMatrix QPMatrix;
}
#include "apollo_msgs/msg/apolloplanning_quadratic_programming_problem_set.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_quadratic_programming_problem_set.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningQuadraticProgrammingProblemSet QuadraticProgrammingProblemSet;
}