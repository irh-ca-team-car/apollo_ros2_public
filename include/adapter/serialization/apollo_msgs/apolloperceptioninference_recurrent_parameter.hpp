#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_recurrent_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRecurrentParameter &msg) ;
    ApolloperceptioninferenceRecurrentParameter from_json_ApolloperceptioninferenceRecurrentParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceRecurrentParameter from_json<ApolloperceptioninferenceRecurrentParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRecurrentParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRecurrentParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRecurrentParameter & dt);
}
