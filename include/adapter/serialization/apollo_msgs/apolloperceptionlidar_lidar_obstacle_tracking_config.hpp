#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_lidar_obstacle_tracking_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarLidarObstacleTrackingConfig &msg) ;
    ApolloperceptionlidarLidarObstacleTrackingConfig from_json_ApolloperceptionlidarLidarObstacleTrackingConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarLidarObstacleTrackingConfig from_json<ApolloperceptionlidarLidarObstacleTrackingConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarLidarObstacleTrackingConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarLidarObstacleTrackingConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarLidarObstacleTrackingConfig & dt);
}
