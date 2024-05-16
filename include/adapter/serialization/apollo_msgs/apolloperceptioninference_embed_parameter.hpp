#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_embed_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceEmbedParameter &msg) ;
    ApolloperceptioninferenceEmbedParameter from_json_ApolloperceptioninferenceEmbedParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceEmbedParameter from_json<ApolloperceptioninferenceEmbedParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceEmbedParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceEmbedParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceEmbedParameter & dt);
}
