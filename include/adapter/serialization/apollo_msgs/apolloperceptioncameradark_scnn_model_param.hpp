#pragma once
#include "apollo_msgs/msg/apolloperceptioncameradark_scnn_model_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradarkSCNNModelParam &msg) ;
    ApolloperceptioncameradarkSCNNModelParam from_json_ApolloperceptioncameradarkSCNNModelParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameradarkSCNNModelParam from_json<ApolloperceptioncameradarkSCNNModelParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradarkSCNNModelParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradarkSCNNModelParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradarkSCNNModelParam & dt);
}
