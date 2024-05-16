#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_normalize_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNormalizeParameter &msg) ;
    ApolloperceptioninferenceNormalizeParameter from_json_ApolloperceptioninferenceNormalizeParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceNormalizeParameter from_json<ApolloperceptioninferenceNormalizeParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNormalizeParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNormalizeParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNormalizeParameter & dt);
}
