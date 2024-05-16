#pragma once
#include "apollo_msgs/msg/apolloprediction_net_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_layer_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_verification_sample.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_performance.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionNetParameter &msg) ;
    ApollopredictionNetParameter from_json_ApollopredictionNetParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionNetParameter from_json<ApollopredictionNetParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionNetParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionNetParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionNetParameter & dt);
}
