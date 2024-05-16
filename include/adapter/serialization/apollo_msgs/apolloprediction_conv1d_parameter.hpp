#pragma once
#include "apollo_msgs/msg/apolloprediction_conv1d_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_tensor_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionConv1dParameter &msg) ;
    ApollopredictionConv1dParameter from_json_ApollopredictionConv1dParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionConv1dParameter from_json<ApollopredictionConv1dParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionConv1dParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionConv1dParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionConv1dParameter & dt);
}
