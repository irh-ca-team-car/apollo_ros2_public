#pragma once
#include "apollo_msgs/msg/apolloperception_traffic_light_detection.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionTrafficLightDetection &msg) ;
    ApolloperceptionTrafficLightDetection from_json_ApolloperceptionTrafficLightDetection (nlohmann::json obj) ;
    template <>
    ApolloperceptionTrafficLightDetection from_json<ApolloperceptionTrafficLightDetection>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionTrafficLightDetection &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionTrafficLightDetection & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionTrafficLightDetection & dt);
}
