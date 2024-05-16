#pragma once
#include "apollo_msgs/msg/apolloprediction_concatenate_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionConcatenateParameter &msg) ;
    ApollopredictionConcatenateParameter from_json_ApollopredictionConcatenateParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionConcatenateParameter from_json<ApollopredictionConcatenateParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionConcatenateParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionConcatenateParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionConcatenateParameter & dt);
}
