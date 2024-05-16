#pragma once
#include "apollo_msgs/msg/apolloprediction_stop_sign.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionStopSign &msg) ;
    ApollopredictionStopSign from_json_ApollopredictionStopSign (nlohmann::json obj) ;
    template <>
    ApollopredictionStopSign from_json<ApollopredictionStopSign>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionStopSign &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionStopSign & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionStopSign & dt);
}
