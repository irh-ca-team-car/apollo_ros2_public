#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_lane_line_cubic_curve.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraLaneLineCubicCurve &msg) ;
    ApolloperceptioncameraLaneLineCubicCurve from_json_ApolloperceptioncameraLaneLineCubicCurve (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraLaneLineCubicCurve from_json<ApolloperceptioncameraLaneLineCubicCurve>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraLaneLineCubicCurve &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraLaneLineCubicCurve & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraLaneLineCubicCurve & dt);
}
