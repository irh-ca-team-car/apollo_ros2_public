#pragma once
#include "apollo_msgs/msg/apolloperceptiononboard_lane_detection.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardLaneDetection &msg) ;
    ApolloperceptiononboardLaneDetection from_json_ApolloperceptiononboardLaneDetection (nlohmann::json obj) ;
    template <>
    ApolloperceptiononboardLaneDetection from_json<ApolloperceptiononboardLaneDetection>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardLaneDetection &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardLaneDetection & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardLaneDetection & dt);
}
