#pragma once
#include "apollo_msgs/msg/apolloprediction_layer_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_layer_parameteroneof_layers.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLayerParameter &msg) ;
    ApollopredictionLayerParameter from_json_ApollopredictionLayerParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionLayerParameter from_json<ApollopredictionLayerParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLayerParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLayerParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLayerParameter & dt);
}
