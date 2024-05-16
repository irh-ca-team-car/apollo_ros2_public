#pragma once
#include "apollo_msgs/msg/apolloprediction_prediction_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_perception_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_trajectory.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_intent.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_priority.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionObstacle &msg) ;
    ApollopredictionPredictionObstacle from_json_ApollopredictionPredictionObstacle (nlohmann::json obj) ;
    template <>
    ApollopredictionPredictionObstacle from_json<ApollopredictionPredictionObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionObstacle & dt);
}
