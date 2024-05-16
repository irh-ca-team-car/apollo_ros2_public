#pragma once
#include "apollo_msgs/msg/apolloprediction_obstacle_priority.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionObstaclePriority &msg) ;
    ApollopredictionObstaclePriority from_json_ApollopredictionObstaclePriority (nlohmann::json obj) ;
    template <>
    ApollopredictionObstaclePriority from_json<ApollopredictionObstaclePriority>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionObstaclePriority &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionObstaclePriority & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionObstaclePriority & dt);
}
