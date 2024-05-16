#pragma once
#include "apollo_msgs/msg/apolloprediction_activation_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionActivationParameter &msg) ;
    ApollopredictionActivationParameter from_json_ApollopredictionActivationParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionActivationParameter from_json<ApollopredictionActivationParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionActivationParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionActivationParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionActivationParameter & dt);
}
