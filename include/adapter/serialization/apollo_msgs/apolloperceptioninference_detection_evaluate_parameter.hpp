#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_detection_evaluate_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_resize_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDetectionEvaluateParameter &msg) ;
    ApolloperceptioninferenceDetectionEvaluateParameter from_json_ApolloperceptioninferenceDetectionEvaluateParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDetectionEvaluateParameter from_json<ApolloperceptioninferenceDetectionEvaluateParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDetectionEvaluateParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDetectionEvaluateParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDetectionEvaluateParameter & dt);
}
