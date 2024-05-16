#pragma once
#include "apollo_msgs/msg/apolloperceptioncameradark_scnn_dark_scnn_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradark_scnn_model_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradark_scnn_network_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradarkSCNNDarkSCNNParam &msg) ;
    ApolloperceptioncameradarkSCNNDarkSCNNParam from_json_ApolloperceptioncameradarkSCNNDarkSCNNParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameradarkSCNNDarkSCNNParam from_json<ApolloperceptioncameradarkSCNNDarkSCNNParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradarkSCNNDarkSCNNParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradarkSCNNDarkSCNNParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradarkSCNNDarkSCNNParam & dt);
}
