#pragma once
#include "apollo_msgs/msg/avg_pool1d_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const AvgPool1dParameter &msg) ;
    AvgPool1dParameter from_json_AvgPool1dParameter (nlohmann::json obj) ;
    template <>
    AvgPool1dParameter from_json<AvgPool1dParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, AvgPool1dParameter &dt);
    std::ostream & operator<<(std::ostream & os, const AvgPool1dParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const AvgPool1dParameter & dt);
}
