#pragma once
#include "apollo_msgs/msg/apolloplanning_obstacle_trajectory_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_perception_obstacle_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_trajectory_point_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObstacleTrajectoryFeature &msg) ;
    ApolloplanningObstacleTrajectoryFeature from_json_ApolloplanningObstacleTrajectoryFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningObstacleTrajectoryFeature from_json<ApolloplanningObstacleTrajectoryFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObstacleTrajectoryFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObstacleTrajectoryFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObstacleTrajectoryFeature & dt);
}
