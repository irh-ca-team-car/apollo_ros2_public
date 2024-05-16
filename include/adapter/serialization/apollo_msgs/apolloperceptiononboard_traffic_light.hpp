#pragma once
#include "apollo_msgs/msg/apolloperceptiononboard_traffic_light.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardTrafficLight &msg) ;
    ApolloperceptiononboardTrafficLight from_json_ApolloperceptiononboardTrafficLight (nlohmann::json obj) ;
    template <>
    ApolloperceptiononboardTrafficLight from_json<ApolloperceptiononboardTrafficLight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardTrafficLight &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardTrafficLight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardTrafficLight & dt);
}
