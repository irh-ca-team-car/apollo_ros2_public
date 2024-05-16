#pragma once
#include "apollo_msgs/msg/max_pool1d_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const MaxPool1dParameter &msg) ;
    MaxPool1dParameter from_json_MaxPool1dParameter (nlohmann::json obj) ;
    template <>
    MaxPool1dParameter from_json<MaxPool1dParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, MaxPool1dParameter &dt);
    std::ostream & operator<<(std::ostream & os, const MaxPool1dParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const MaxPool1dParameter & dt);
}
