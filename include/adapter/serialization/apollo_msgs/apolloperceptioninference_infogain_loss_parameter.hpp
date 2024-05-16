#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_infogain_loss_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceInfogainLossParameter &msg) ;
    ApolloperceptioninferenceInfogainLossParameter from_json_ApolloperceptioninferenceInfogainLossParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceInfogainLossParameter from_json<ApolloperceptioninferenceInfogainLossParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceInfogainLossParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceInfogainLossParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceInfogainLossParameter & dt);
}
