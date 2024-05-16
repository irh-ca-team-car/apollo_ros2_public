#pragma once
#include "apollo_msgs/msg/apolloprediction_obstacle_intent.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionObstacleIntent &msg) ;
    ApollopredictionObstacleIntent from_json_ApollopredictionObstacleIntent (nlohmann::json obj) ;
    template <>
    ApollopredictionObstacleIntent from_json<ApollopredictionObstacleIntent>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionObstacleIntent &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionObstacleIntent & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionObstacleIntent & dt);
}
