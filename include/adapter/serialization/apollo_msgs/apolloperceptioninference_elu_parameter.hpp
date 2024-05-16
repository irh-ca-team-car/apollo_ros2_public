#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_elu_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceELUParameter &msg) ;
    ApolloperceptioninferenceELUParameter from_json_ApolloperceptioninferenceELUParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceELUParameter from_json<ApolloperceptioninferenceELUParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceELUParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceELUParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceELUParameter & dt);
}
