#pragma once
#include "apollo_msgs/msg/input_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const InputParameter &msg) ;
    InputParameter from_json_InputParameter (nlohmann::json obj) ;
    template <>
    InputParameter from_json<InputParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, InputParameter &dt);
    std::ostream & operator<<(std::ostream & os, const InputParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const InputParameter & dt);
}
