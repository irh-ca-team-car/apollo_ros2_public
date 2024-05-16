#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_threshold_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceThresholdParameter &msg) ;
    ApolloperceptioninferenceThresholdParameter from_json_ApolloperceptioninferenceThresholdParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceThresholdParameter from_json<ApolloperceptioninferenceThresholdParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceThresholdParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceThresholdParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceThresholdParameter & dt);
}
