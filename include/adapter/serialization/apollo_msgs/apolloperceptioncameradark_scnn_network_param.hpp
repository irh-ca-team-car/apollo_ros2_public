#pragma once
#include "apollo_msgs/msg/apolloperceptioncameradark_scnn_network_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradarkSCNNNetworkParam &msg) ;
    ApolloperceptioncameradarkSCNNNetworkParam from_json_ApolloperceptioncameradarkSCNNNetworkParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameradarkSCNNNetworkParam from_json<ApolloperceptioncameradarkSCNNNetworkParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradarkSCNNNetworkParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradarkSCNNNetworkParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradarkSCNNNetworkParam & dt);
}
