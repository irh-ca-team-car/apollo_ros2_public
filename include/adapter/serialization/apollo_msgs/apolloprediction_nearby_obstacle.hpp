#pragma once
#include "apollo_msgs/msg/apolloprediction_nearby_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionNearbyObstacle &msg) ;
    ApollopredictionNearbyObstacle from_json_ApollopredictionNearbyObstacle (nlohmann::json obj) ;
    template <>
    ApollopredictionNearbyObstacle from_json<ApollopredictionNearbyObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionNearbyObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionNearbyObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionNearbyObstacle & dt);
}
