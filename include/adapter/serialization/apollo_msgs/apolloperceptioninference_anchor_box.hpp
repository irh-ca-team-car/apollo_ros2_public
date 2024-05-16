#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_anchor_box.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnchorBox &msg) ;
    ApolloperceptioninferenceAnchorBox from_json_ApolloperceptioninferenceAnchorBox (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceAnchorBox from_json<ApolloperceptioninferenceAnchorBox>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnchorBox &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnchorBox & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnchorBox & dt);
}
