#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_filler_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceFillerParameter &msg) ;
    ApolloperceptioninferenceFillerParameter from_json_ApolloperceptioninferenceFillerParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceFillerParameter from_json<ApolloperceptioninferenceFillerParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceFillerParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceFillerParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceFillerParameter & dt);
}
