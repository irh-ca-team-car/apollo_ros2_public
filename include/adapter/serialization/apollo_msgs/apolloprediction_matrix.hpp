#pragma once
#include "apollo_msgs/msg/apolloprediction_matrix.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_vector.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionMatrix &msg) ;
    ApollopredictionMatrix from_json_ApollopredictionMatrix (nlohmann::json obj) ;
    template <>
    ApollopredictionMatrix from_json<ApollopredictionMatrix>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionMatrix &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionMatrix & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionMatrix & dt);
}
