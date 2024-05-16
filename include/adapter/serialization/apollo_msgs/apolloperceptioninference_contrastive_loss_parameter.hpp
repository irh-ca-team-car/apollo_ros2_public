#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_contrastive_loss_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceContrastiveLossParameter &msg) ;
    ApolloperceptioninferenceContrastiveLossParameter from_json_ApolloperceptioninferenceContrastiveLossParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceContrastiveLossParameter from_json<ApolloperceptioninferenceContrastiveLossParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceContrastiveLossParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceContrastiveLossParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceContrastiveLossParameter & dt);
}
