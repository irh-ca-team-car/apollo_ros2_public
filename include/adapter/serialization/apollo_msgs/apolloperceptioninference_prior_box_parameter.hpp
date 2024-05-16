#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_prior_box_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePriorBoxParameter &msg) ;
    ApolloperceptioninferencePriorBoxParameter from_json_ApolloperceptioninferencePriorBoxParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferencePriorBoxParameter from_json<ApolloperceptioninferencePriorBoxParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePriorBoxParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePriorBoxParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePriorBoxParameter & dt);
}
