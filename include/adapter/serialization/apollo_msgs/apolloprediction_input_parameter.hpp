#pragma once
#include "apollo_msgs/msg/apolloprediction_input_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionInputParameter &msg) ;
    ApollopredictionInputParameter from_json_ApollopredictionInputParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionInputParameter from_json<ApollopredictionInputParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionInputParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionInputParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionInputParameter & dt);
}
