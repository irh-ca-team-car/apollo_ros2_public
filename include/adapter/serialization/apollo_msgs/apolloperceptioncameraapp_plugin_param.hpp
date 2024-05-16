#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_plugin_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappPluginParam &msg) ;
    ApolloperceptioncameraappPluginParam from_json_ApolloperceptioncameraappPluginParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappPluginParam from_json<ApolloperceptioncameraappPluginParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappPluginParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappPluginParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappPluginParam & dt);
}
