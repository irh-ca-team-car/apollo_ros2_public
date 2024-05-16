#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_net_state_rule.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNetStateRule &msg) ;
    ApolloperceptioninferenceNetStateRule from_json_ApolloperceptioninferenceNetStateRule (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceNetStateRule from_json<ApolloperceptioninferenceNetStateRule>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNetStateRule &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNetStateRule & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNetStateRule & dt);
}
