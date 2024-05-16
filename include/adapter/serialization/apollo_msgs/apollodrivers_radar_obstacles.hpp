#pragma once
#include "apollo_msgs/msg/apollodrivers_radar_obstacles.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodrivers_radar_obstaclesradar_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRadarObstacles &msg) ;
    ApollodriversRadarObstacles from_json_ApollodriversRadarObstacles (nlohmann::json obj) ;
    template <>
    ApollodriversRadarObstacles from_json<ApollodriversRadarObstacles>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRadarObstacles &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversRadarObstacles & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRadarObstacles & dt);
}
