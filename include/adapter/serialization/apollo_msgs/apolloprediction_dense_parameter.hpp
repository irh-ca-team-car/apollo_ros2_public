#pragma once
#include "apollo_msgs/msg/apolloprediction_dense_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_tensor_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionDenseParameter &msg) ;
    ApollopredictionDenseParameter from_json_ApollopredictionDenseParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionDenseParameter from_json<ApollopredictionDenseParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionDenseParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionDenseParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionDenseParameter & dt);
}
