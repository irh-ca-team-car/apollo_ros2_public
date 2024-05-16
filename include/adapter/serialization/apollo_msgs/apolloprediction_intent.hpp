#pragma once
#include "apollo_msgs/msg/apolloprediction_intent.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionIntent &msg) ;
    ApollopredictionIntent from_json_ApollopredictionIntent (nlohmann::json obj) ;
    template <>
    ApollopredictionIntent from_json<ApollopredictionIntent>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionIntent &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionIntent & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionIntent & dt);
}
