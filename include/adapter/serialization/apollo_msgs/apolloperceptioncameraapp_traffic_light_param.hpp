#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_traffic_light_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_detector_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_tracker_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappTrafficLightParam &msg) ;
    ApolloperceptioncameraappTrafficLightParam from_json_ApolloperceptioncameraappTrafficLightParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappTrafficLightParam from_json<ApolloperceptioncameraappTrafficLightParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappTrafficLightParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappTrafficLightParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappTrafficLightParam & dt);
}
