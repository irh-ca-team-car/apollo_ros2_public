#pragma once
#include "apollo_msgs/msg/apolloprediction_verification_sample.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_tensor_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionVerificationSample &msg) ;
    ApollopredictionVerificationSample from_json_ApollopredictionVerificationSample (nlohmann::json obj) ;
    template <>
    ApollopredictionVerificationSample from_json<ApollopredictionVerificationSample>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionVerificationSample &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionVerificationSample & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionVerificationSample & dt);
}
