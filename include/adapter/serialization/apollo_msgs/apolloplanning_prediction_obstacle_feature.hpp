#pragma once
#include "apollo_msgs/msg/apolloplanning_prediction_obstacle_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_intent.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_priority.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_prediction_trajectory_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPredictionObstacleFeature &msg) ;
    ApolloplanningPredictionObstacleFeature from_json_ApolloplanningPredictionObstacleFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningPredictionObstacleFeature from_json<ApolloplanningPredictionObstacleFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPredictionObstacleFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPredictionObstacleFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPredictionObstacleFeature & dt);
}
