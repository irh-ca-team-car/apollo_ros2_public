#pragma once
#include "apollo_msgs/msg/apolloprediction_batch_normalization_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_tensor_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionBatchNormalizationParameter &msg) ;
    ApollopredictionBatchNormalizationParameter from_json_ApollopredictionBatchNormalizationParameter (nlohmann::json obj) ;
    template <>
    ApollopredictionBatchNormalizationParameter from_json<ApollopredictionBatchNormalizationParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionBatchNormalizationParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionBatchNormalizationParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionBatchNormalizationParameter & dt);
}
