#pragma once
#include "apollo_msgs/msg/apolloprediction_lstm_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_tensor_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLSTMParameter &msg) ;
    ApollopredictionLSTMParameter from_json_ApollopredictionLSTMParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionLSTMParameter from_json<ApollopredictionLSTMParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLSTMParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLSTMParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLSTMParameter & dt);
}
