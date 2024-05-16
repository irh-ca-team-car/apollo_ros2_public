#pragma once
#include "apollo_msgs/msg/apolloperceptiononboard_lidar_segmentation_component_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardLidarSegmentationComponentConfig &msg) ;
    ApolloperceptiononboardLidarSegmentationComponentConfig from_json_ApolloperceptiononboardLidarSegmentationComponentConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptiononboardLidarSegmentationComponentConfig from_json<ApolloperceptiononboardLidarSegmentationComponentConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardLidarSegmentationComponentConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardLidarSegmentationComponentConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardLidarSegmentationComponentConfig & dt);
}
