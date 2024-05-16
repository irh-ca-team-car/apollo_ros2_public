#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_resize_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceResizeParameter &msg) ;
    ApolloperceptioninferenceResizeParameter from_json_ApolloperceptioninferenceResizeParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceResizeParameter from_json<ApolloperceptioninferenceResizeParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceResizeParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceResizeParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceResizeParameter & dt);
}
