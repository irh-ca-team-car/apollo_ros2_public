#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_debug_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappDebugParam &msg) ;
    ApolloperceptioncameraappDebugParam from_json_ApolloperceptioncameraappDebugParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappDebugParam from_json<ApolloperceptioncameraappDebugParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappDebugParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappDebugParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappDebugParam & dt);
}
