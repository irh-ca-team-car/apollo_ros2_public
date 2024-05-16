#pragma once
#include "apollo_msgs/msg/apollothird_party_perception_radar_obstacles.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollothird_party_perception_radar_obstaclesradar_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollothirdPartyPerceptionRadarObstacles &msg) ;
    ApollothirdPartyPerceptionRadarObstacles from_json_ApollothirdPartyPerceptionRadarObstacles (nlohmann::json obj) ;
    template <>
    ApollothirdPartyPerceptionRadarObstacles from_json<ApollothirdPartyPerceptionRadarObstacles>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollothirdPartyPerceptionRadarObstacles &dt);
    std::ostream & operator<<(std::ostream & os, const ApollothirdPartyPerceptionRadarObstacles & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollothirdPartyPerceptionRadarObstacles & dt);
}
