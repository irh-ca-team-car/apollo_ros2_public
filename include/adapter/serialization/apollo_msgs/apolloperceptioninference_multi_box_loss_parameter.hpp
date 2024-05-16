#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_multi_box_loss_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_non_maximum_suppression_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceMultiBoxLossParameter &msg) ;
    ApolloperceptioninferenceMultiBoxLossParameter from_json_ApolloperceptioninferenceMultiBoxLossParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceMultiBoxLossParameter from_json<ApolloperceptioninferenceMultiBoxLossParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceMultiBoxLossParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceMultiBoxLossParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceMultiBoxLossParameter & dt);
}
