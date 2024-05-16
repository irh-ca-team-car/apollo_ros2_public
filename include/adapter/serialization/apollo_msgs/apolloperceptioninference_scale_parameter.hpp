#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_scale_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceScaleParameter &msg) ;
    ApolloperceptioninferenceScaleParameter from_json_ApolloperceptioninferenceScaleParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceScaleParameter from_json<ApolloperceptioninferenceScaleParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceScaleParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceScaleParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceScaleParameter & dt);
}
