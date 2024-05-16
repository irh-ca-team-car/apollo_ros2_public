#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_dropout_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDropoutParameter &msg) ;
    ApolloperceptioninferenceDropoutParameter from_json_ApolloperceptioninferenceDropoutParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDropoutParameter from_json<ApolloperceptioninferenceDropoutParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDropoutParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDropoutParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDropoutParameter & dt);
}
