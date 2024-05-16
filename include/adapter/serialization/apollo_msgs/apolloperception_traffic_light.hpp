#pragma once
#include "apollo_msgs/msg/apolloperception_traffic_light.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionTrafficLight &msg) ;
    ApolloperceptionTrafficLight from_json_ApolloperceptionTrafficLight (nlohmann::json obj) ;
    template <>
    ApolloperceptionTrafficLight from_json<ApolloperceptionTrafficLight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionTrafficLight &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionTrafficLight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionTrafficLight & dt);
}
