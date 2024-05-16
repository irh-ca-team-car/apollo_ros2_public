#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_slice_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSliceParameter &msg) ;
    ApolloperceptioninferenceSliceParameter from_json_ApolloperceptioninferenceSliceParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceSliceParameter from_json<ApolloperceptioninferenceSliceParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSliceParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSliceParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSliceParameter & dt);
}
