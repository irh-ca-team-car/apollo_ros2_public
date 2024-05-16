#pragma once
#include "apollo_msgs/msg/apolloplanning_open_space_trajectory_optimizer_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_hybrid_a_star_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_dual_variable_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_distance_approach_trajectory_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_planner_open_space_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceTrajectoryOptimizerConfig &msg) ;
    ApolloplanningOpenSpaceTrajectoryOptimizerConfig from_json_ApolloplanningOpenSpaceTrajectoryOptimizerConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningOpenSpaceTrajectoryOptimizerConfig from_json<ApolloplanningOpenSpaceTrajectoryOptimizerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceTrajectoryOptimizerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceTrajectoryOptimizerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceTrajectoryOptimizerConfig & dt);
}
