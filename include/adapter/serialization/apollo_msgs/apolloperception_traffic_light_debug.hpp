#pragma once
#include "apollo_msgs/msg/apolloperception_traffic_light_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light_box.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionTrafficLightDebug &msg) ;
    ApolloperceptionTrafficLightDebug from_json_ApolloperceptionTrafficLightDebug (nlohmann::json obj) ;
    template <>
    ApolloperceptionTrafficLightDebug from_json<ApolloperceptionTrafficLightDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionTrafficLightDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionTrafficLightDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionTrafficLightDebug & dt);
}
