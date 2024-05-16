#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_power_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePowerParameter &msg) ;
    ApolloperceptioninferencePowerParameter from_json_ApolloperceptioninferencePowerParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferencePowerParameter from_json<ApolloperceptioninferencePowerParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePowerParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePowerParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePowerParameter & dt);
}
