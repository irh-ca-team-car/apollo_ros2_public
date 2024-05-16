#pragma once
#include "apollo_msgs/msg/apolloprediction_lane_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneObstacle &msg) ;
    ApollopredictionLaneObstacle from_json_ApollopredictionLaneObstacle (nlohmann::json obj) ;
    template <>
    ApollopredictionLaneObstacle from_json<ApollopredictionLaneObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneObstacle & dt);
}
