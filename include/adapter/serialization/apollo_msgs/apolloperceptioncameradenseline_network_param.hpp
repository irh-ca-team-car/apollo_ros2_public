#pragma once
#include "apollo_msgs/msg/apolloperceptioncameradenseline_network_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradenselineNetworkParam &msg) ;
    ApolloperceptioncameradenselineNetworkParam from_json_ApolloperceptioncameradenselineNetworkParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameradenselineNetworkParam from_json<ApolloperceptioncameradenselineNetworkParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradenselineNetworkParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradenselineNetworkParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradenselineNetworkParam & dt);
}
