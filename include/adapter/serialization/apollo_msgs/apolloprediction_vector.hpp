#pragma once
#include "apollo_msgs/msg/apolloprediction_vector.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionVector &msg) ;
    ApollopredictionVector from_json_ApollopredictionVector (nlohmann::json obj) ;
    template <>
    ApollopredictionVector from_json<ApollopredictionVector>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionVector &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionVector & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionVector & dt);
}
