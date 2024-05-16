#pragma once
#include "apollo_msgs/msg/apollothird_party_perception_radar_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollothirdPartyPerceptionRadarObstacle &msg) ;
    ApollothirdPartyPerceptionRadarObstacle from_json_ApollothirdPartyPerceptionRadarObstacle (nlohmann::json obj) ;
    template <>
    ApollothirdPartyPerceptionRadarObstacle from_json<ApollothirdPartyPerceptionRadarObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollothirdPartyPerceptionRadarObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApollothirdPartyPerceptionRadarObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollothirdPartyPerceptionRadarObstacle & dt);
}
