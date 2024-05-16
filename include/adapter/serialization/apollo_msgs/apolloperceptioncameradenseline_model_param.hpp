#pragma once
#include "apollo_msgs/msg/apolloperceptioncameradenseline_model_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradenselineModelParam &msg) ;
    ApolloperceptioncameradenselineModelParam from_json_ApolloperceptioncameradenselineModelParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameradenselineModelParam from_json<ApolloperceptioncameradenselineModelParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradenselineModelParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradenselineModelParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradenselineModelParam & dt);
}
