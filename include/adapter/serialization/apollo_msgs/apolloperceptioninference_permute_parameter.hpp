#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_permute_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePermuteParameter &msg) ;
    ApolloperceptioninferencePermuteParameter from_json_ApolloperceptioninferencePermuteParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferencePermuteParameter from_json<ApolloperceptioninferencePermuteParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePermuteParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePermuteParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePermuteParameter & dt);
}
