#pragma once
#include "apollo_msgs/msg/conv1d_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/tensor_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Conv1dParameter &msg) ;
    Conv1dParameter from_json_Conv1dParameter (nlohmann::json obj) ;
    template <>
    Conv1dParameter from_json<Conv1dParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Conv1dParameter &dt);
    std::ostream & operator<<(std::ostream & os, const Conv1dParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Conv1dParameter & dt);
}
