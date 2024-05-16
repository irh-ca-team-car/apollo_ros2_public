#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_net_state.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNetState &msg) ;
    ApolloperceptioninferenceNetState from_json_ApolloperceptioninferenceNetState (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceNetState from_json<ApolloperceptioninferenceNetState>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNetState &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNetState & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNetState & dt);
}
