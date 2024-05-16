#pragma once
#include "apollo_msgs/msg/apolloprediction_obstacle_history.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionObstacleHistory &msg) ;
    ApollopredictionObstacleHistory from_json_ApollopredictionObstacleHistory (nlohmann::json obj) ;
    template <>
    ApollopredictionObstacleHistory from_json<ApollopredictionObstacleHistory>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionObstacleHistory &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionObstacleHistory & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionObstacleHistory & dt);
}
