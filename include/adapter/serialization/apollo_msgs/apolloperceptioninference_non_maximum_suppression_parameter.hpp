#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_non_maximum_suppression_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNonMaximumSuppressionParameter &msg) ;
    ApolloperceptioninferenceNonMaximumSuppressionParameter from_json_ApolloperceptioninferenceNonMaximumSuppressionParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceNonMaximumSuppressionParameter from_json<ApolloperceptioninferenceNonMaximumSuppressionParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNonMaximumSuppressionParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNonMaximumSuppressionParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNonMaximumSuppressionParameter & dt);
}
