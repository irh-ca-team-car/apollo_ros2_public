#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_lidar_obstacle_segmentation_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarLidarObstacleSegmentationConfig &msg) ;
    ApolloperceptionlidarLidarObstacleSegmentationConfig from_json_ApolloperceptionlidarLidarObstacleSegmentationConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarLidarObstacleSegmentationConfig from_json<ApolloperceptionlidarLidarObstacleSegmentationConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarLidarObstacleSegmentationConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarLidarObstacleSegmentationConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarLidarObstacleSegmentationConfig & dt);
}
