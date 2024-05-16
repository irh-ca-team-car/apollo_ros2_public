#pragma once
#include "apollo_msgs/msg/apolloprediction_prediction_obstacles.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_intent.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_scenario.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionObstacles &msg) ;
    ApollopredictionPredictionObstacles from_json_ApollopredictionPredictionObstacles (nlohmann::json obj) ;
    template <>
    ApollopredictionPredictionObstacles from_json<ApollopredictionPredictionObstacles>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionObstacles &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionObstacles & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionObstacles & dt);
}
