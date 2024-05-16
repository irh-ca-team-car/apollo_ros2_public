#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_detection_output_ssd_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_gen_anchor_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_nmsssd_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDetectionOutputSSDParameter &msg) ;
    ApolloperceptioninferenceDetectionOutputSSDParameter from_json_ApolloperceptioninferenceDetectionOutputSSDParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDetectionOutputSSDParameter from_json<ApolloperceptioninferenceDetectionOutputSSDParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDetectionOutputSSDParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDetectionOutputSSDParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDetectionOutputSSDParameter & dt);
}
