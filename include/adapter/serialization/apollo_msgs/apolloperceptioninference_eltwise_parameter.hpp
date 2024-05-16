#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_eltwise_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceEltwiseParameter &msg) ;
    ApolloperceptioninferenceEltwiseParameter from_json_ApolloperceptioninferenceEltwiseParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceEltwiseParameter from_json<ApolloperceptioninferenceEltwiseParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceEltwiseParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceEltwiseParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceEltwiseParameter & dt);
}
