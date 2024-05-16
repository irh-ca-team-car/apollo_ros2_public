#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_exp_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceExpParameter &msg) ;
    ApolloperceptioninferenceExpParameter from_json_ApolloperceptioninferenceExpParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceExpParameter from_json<ApolloperceptioninferenceExpParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceExpParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceExpParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceExpParameter & dt);
}
