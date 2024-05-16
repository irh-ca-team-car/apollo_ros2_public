#pragma once
#include "apollo_msgs/msg/apolloperceptioncameradenseline_denseline_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradenseline_model_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradenseline_network_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradenselineDenselineParam &msg) ;
    ApolloperceptioncameradenselineDenselineParam from_json_ApolloperceptioncameradenselineDenselineParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameradenselineDenselineParam from_json<ApolloperceptioncameradenselineDenselineParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradenselineDenselineParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradenselineDenselineParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradenselineDenselineParam & dt);
}
