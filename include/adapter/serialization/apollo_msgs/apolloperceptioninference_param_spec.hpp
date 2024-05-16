#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_param_spec.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceParamSpec &msg) ;
    ApolloperceptioninferenceParamSpec from_json_ApolloperceptioninferenceParamSpec (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceParamSpec from_json<ApolloperceptioninferenceParamSpec>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceParamSpec &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceParamSpec & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceParamSpec & dt);
}
