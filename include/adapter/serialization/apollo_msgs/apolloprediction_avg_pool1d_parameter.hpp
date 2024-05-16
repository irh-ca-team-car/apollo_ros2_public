#pragma once
#include "apollo_msgs/msg/apolloprediction_avg_pool1d_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionAvgPool1dParameter &msg) ;
    ApollopredictionAvgPool1dParameter from_json_ApollopredictionAvgPool1dParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionAvgPool1dParameter from_json<ApollopredictionAvgPool1dParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionAvgPool1dParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionAvgPool1dParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionAvgPool1dParameter & dt);
}
