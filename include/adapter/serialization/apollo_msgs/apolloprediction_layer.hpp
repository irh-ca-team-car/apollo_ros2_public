#pragma once
#include "apollo_msgs/msg/apolloprediction_layer.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_matrix.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_vector.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLayer &msg) ;
    ApollopredictionLayer from_json_ApollopredictionLayer (nlohmann::json obj) ;
    template <>
    ApollopredictionLayer from_json<ApollopredictionLayer>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLayer &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLayer & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLayer & dt);
}
