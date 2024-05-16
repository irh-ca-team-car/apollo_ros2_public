#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_gen_anchor_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceGenAnchorParameter &msg) ;
    ApolloperceptioninferenceGenAnchorParameter from_json_ApolloperceptioninferenceGenAnchorParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceGenAnchorParameter from_json<ApolloperceptioninferenceGenAnchorParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceGenAnchorParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceGenAnchorParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceGenAnchorParameter & dt);
}
