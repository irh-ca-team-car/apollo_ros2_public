#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_hinge_loss_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceHingeLossParameter &msg) ;
    ApolloperceptioninferenceHingeLossParameter from_json_ApolloperceptioninferenceHingeLossParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceHingeLossParameter from_json<ApolloperceptioninferenceHingeLossParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceHingeLossParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceHingeLossParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceHingeLossParameter & dt);
}
