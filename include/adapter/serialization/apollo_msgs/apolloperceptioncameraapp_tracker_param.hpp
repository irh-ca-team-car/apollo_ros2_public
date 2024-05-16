#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_tracker_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_plugin_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappTrackerParam &msg) ;
    ApolloperceptioncameraappTrackerParam from_json_ApolloperceptioncameraappTrackerParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappTrackerParam from_json<ApolloperceptioncameraappTrackerParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappTrackerParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappTrackerParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappTrackerParam & dt);
}
