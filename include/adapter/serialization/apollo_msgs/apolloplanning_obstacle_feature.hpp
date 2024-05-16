#pragma once
#include "apollo_msgs/msg/apolloplanning_obstacle_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_obstacle_trajectory_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_prediction_obstacle_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObstacleFeature &msg) ;
    ApolloplanningObstacleFeature from_json_ApolloplanningObstacleFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningObstacleFeature from_json<ApolloplanningObstacleFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObstacleFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObstacleFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObstacleFeature & dt);
}
