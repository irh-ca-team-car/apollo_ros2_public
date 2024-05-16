#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_ground_service_detector_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarGroundServiceDetectorConfig &msg) ;
    ApolloperceptionlidarGroundServiceDetectorConfig from_json_ApolloperceptionlidarGroundServiceDetectorConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarGroundServiceDetectorConfig from_json<ApolloperceptionlidarGroundServiceDetectorConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarGroundServiceDetectorConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarGroundServiceDetectorConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarGroundServiceDetectorConfig & dt);
}
