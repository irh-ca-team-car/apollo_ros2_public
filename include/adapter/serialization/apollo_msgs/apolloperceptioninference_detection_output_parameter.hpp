#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_detection_output_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_non_maximum_suppression_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_save_output_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDetectionOutputParameter &msg) ;
    ApolloperceptioninferenceDetectionOutputParameter from_json_ApolloperceptioninferenceDetectionOutputParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDetectionOutputParameter from_json<ApolloperceptioninferenceDetectionOutputParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDetectionOutputParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDetectionOutputParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDetectionOutputParameter & dt);
}
