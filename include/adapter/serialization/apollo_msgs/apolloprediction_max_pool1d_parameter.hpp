#pragma once
#include "apollo_msgs/msg/apolloprediction_max_pool1d_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionMaxPool1dParameter &msg) ;
    ApollopredictionMaxPool1dParameter from_json_ApollopredictionMaxPool1dParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionMaxPool1dParameter from_json<ApollopredictionMaxPool1dParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionMaxPool1dParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionMaxPool1dParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionMaxPool1dParameter & dt);
}
