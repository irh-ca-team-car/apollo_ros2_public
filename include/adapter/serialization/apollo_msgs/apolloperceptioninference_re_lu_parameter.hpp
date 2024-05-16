#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_re_lu_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceReLUParameter &msg) ;
    ApolloperceptioninferenceReLUParameter from_json_ApolloperceptioninferenceReLUParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceReLUParameter from_json<ApolloperceptioninferenceReLUParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceReLUParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceReLUParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceReLUParameter & dt);
}
