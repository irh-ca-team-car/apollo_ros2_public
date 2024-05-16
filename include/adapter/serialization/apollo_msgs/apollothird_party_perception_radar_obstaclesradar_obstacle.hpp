#pragma once
#include "apollo_msgs/msg/apollothird_party_perception_radar_obstaclesradar_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollothird_party_perception_radar_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollothirdPartyPerceptionRadarObstaclesradarObstacle &msg) ;
    ApollothirdPartyPerceptionRadarObstaclesradarObstacle from_json_ApollothirdPartyPerceptionRadarObstaclesradarObstacle (nlohmann::json obj) ;
    template <>
    ApollothirdPartyPerceptionRadarObstaclesradarObstacle from_json<ApollothirdPartyPerceptionRadarObstaclesradarObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollothirdPartyPerceptionRadarObstaclesradarObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApollothirdPartyPerceptionRadarObstaclesradarObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollothirdPartyPerceptionRadarObstaclesradarObstacle & dt);
}
