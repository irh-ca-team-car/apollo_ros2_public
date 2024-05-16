#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_python_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePythonParameter &msg) ;
    ApolloperceptioninferencePythonParameter from_json_ApolloperceptioninferencePythonParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferencePythonParameter from_json<ApolloperceptioninferencePythonParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePythonParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePythonParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePythonParameter & dt);
}
