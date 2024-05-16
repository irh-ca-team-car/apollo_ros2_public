#pragma once
#include "apollo_msgs/msg/apolloprediction_scenario.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionScenario &msg) ;
    ApollopredictionScenario from_json_ApollopredictionScenario (nlohmann::json obj) ;
    template <>
    ApollopredictionScenario from_json<ApollopredictionScenario>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionScenario &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionScenario & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionScenario & dt);
}
