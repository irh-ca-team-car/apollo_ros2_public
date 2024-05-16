#pragma once
#include "apollo_msgs/msg/apolloperceptiononboard_lidar_detection_component_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardLidarDetectionComponentConfig &msg) ;
    ApolloperceptiononboardLidarDetectionComponentConfig from_json_ApolloperceptiononboardLidarDetectionComponentConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptiononboardLidarDetectionComponentConfig from_json<ApolloperceptiononboardLidarDetectionComponentConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardLidarDetectionComponentConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardLidarDetectionComponentConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardLidarDetectionComponentConfig & dt);
}
