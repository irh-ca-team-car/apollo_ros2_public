#pragma once
#include "apollo_msgs/msg/apolloprediction_tensor_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionTensorParameter &msg) ;
    ApollopredictionTensorParameter from_json_ApollopredictionTensorParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionTensorParameter from_json<ApollopredictionTensorParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionTensorParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionTensorParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionTensorParameter & dt);
}
