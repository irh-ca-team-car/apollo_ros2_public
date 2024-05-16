#pragma once
#include "apollo_msgs/msg/apolloplanning_distance_approach_trajectory_smoother_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_ipopt_solver_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDistanceApproachTrajectorySmootherConfig &msg) ;
    ApolloplanningDistanceApproachTrajectorySmootherConfig from_json_ApolloplanningDistanceApproachTrajectorySmootherConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningDistanceApproachTrajectorySmootherConfig from_json<ApolloplanningDistanceApproachTrajectorySmootherConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDistanceApproachTrajectorySmootherConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDistanceApproachTrajectorySmootherConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDistanceApproachTrajectorySmootherConfig & dt);
}
