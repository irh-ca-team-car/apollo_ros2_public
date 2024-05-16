#pragma once
#include "apollo_msgs/msg/apollodrivers_radar_obstaclesradar_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodrivers_radar_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRadarObstaclesradarObstacle &msg) ;
    ApollodriversRadarObstaclesradarObstacle from_json_ApollodriversRadarObstaclesradarObstacle (nlohmann::json obj) ;
    template <>
    ApollodriversRadarObstaclesradarObstacle from_json<ApollodriversRadarObstaclesradarObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRadarObstaclesradarObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversRadarObstaclesradarObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRadarObstaclesradarObstacle & dt);
}
