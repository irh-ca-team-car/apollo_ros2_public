#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_lidar_obstacle_detection_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarLidarObstacleDetectionConfig &msg) ;
    ApolloperceptionlidarLidarObstacleDetectionConfig from_json_ApolloperceptionlidarLidarObstacleDetectionConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarLidarObstacleDetectionConfig from_json<ApolloperceptionlidarLidarObstacleDetectionConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarLidarObstacleDetectionConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarLidarObstacleDetectionConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarLidarObstacleDetectionConfig & dt);
}
