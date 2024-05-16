#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_distortion_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDistortionParameter &msg) ;
    ApolloperceptioninferenceDistortionParameter from_json_ApolloperceptioninferenceDistortionParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDistortionParameter from_json<ApolloperceptioninferenceDistortionParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDistortionParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDistortionParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDistortionParameter & dt);
}
