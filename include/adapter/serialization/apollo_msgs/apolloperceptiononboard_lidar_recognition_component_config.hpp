#pragma once
#include "apollo_msgs/msg/apolloperceptiononboard_lidar_recognition_component_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardLidarRecognitionComponentConfig &msg) ;
    ApolloperceptiononboardLidarRecognitionComponentConfig from_json_ApolloperceptiononboardLidarRecognitionComponentConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptiononboardLidarRecognitionComponentConfig from_json<ApolloperceptiononboardLidarRecognitionComponentConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardLidarRecognitionComponentConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardLidarRecognitionComponentConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardLidarRecognitionComponentConfig & dt);
}
