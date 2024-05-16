#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_normalized_b_box.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNormalizedBBox &msg) ;
    ApolloperceptioninferenceNormalizedBBox from_json_ApolloperceptioninferenceNormalizedBBox (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceNormalizedBBox from_json<ApolloperceptioninferenceNormalizedBBox>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNormalizedBBox &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNormalizedBBox & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNormalizedBBox & dt);
}
