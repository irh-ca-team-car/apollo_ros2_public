#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_noise_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_salt_pepper_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNoiseParameter &msg) ;
    ApolloperceptioninferenceNoiseParameter from_json_ApolloperceptioninferenceNoiseParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceNoiseParameter from_json<ApolloperceptioninferenceNoiseParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNoiseParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNoiseParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNoiseParameter & dt);
}
