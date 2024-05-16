#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratraffic_lightdetection_detection_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrafficLightdetectionDetectionParam &msg) ;
    ApolloperceptioncameratrafficLightdetectionDetectionParam from_json_ApolloperceptioncameratrafficLightdetectionDetectionParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameratrafficLightdetectionDetectionParam from_json<ApolloperceptioncameratrafficLightdetectionDetectionParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrafficLightdetectionDetectionParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrafficLightdetectionDetectionParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrafficLightdetectionDetectionParam & dt);
}
