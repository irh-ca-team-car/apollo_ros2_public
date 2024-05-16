#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_detector_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_plugin_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappDetectorParam &msg) ;
    ApolloperceptioncameraappDetectorParam from_json_ApolloperceptioncameraappDetectorParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappDetectorParam from_json<ApolloperceptioncameraappDetectorParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappDetectorParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappDetectorParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappDetectorParam & dt);
}
