#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_pooling_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePoolingParameter &msg) ;
    ApolloperceptioninferencePoolingParameter from_json_ApolloperceptioninferencePoolingParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferencePoolingParameter from_json<ApolloperceptioninferencePoolingParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePoolingParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePoolingParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePoolingParameter & dt);
}
