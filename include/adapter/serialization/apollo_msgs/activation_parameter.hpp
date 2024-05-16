#pragma once
#include "apollo_msgs/msg/activation_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ActivationParameter &msg) ;
    ActivationParameter from_json_ActivationParameter (nlohmann::json obj) ;
    template <>
    ActivationParameter from_json<ActivationParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ActivationParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ActivationParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ActivationParameter & dt);
}
