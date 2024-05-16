#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_arg_max_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceArgMaxParameter &msg) ;
    ApolloperceptioninferenceArgMaxParameter from_json_ApolloperceptioninferenceArgMaxParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceArgMaxParameter from_json<ApolloperceptioninferenceArgMaxParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceArgMaxParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceArgMaxParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceArgMaxParameter & dt);
}
