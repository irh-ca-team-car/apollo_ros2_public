#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_postprocessor_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_plugin_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappPostprocessorParam &msg) ;
    ApolloperceptioncameraappPostprocessorParam from_json_ApolloperceptioncameraappPostprocessorParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappPostprocessorParam from_json<ApolloperceptioncameraappPostprocessorParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappPostprocessorParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappPostprocessorParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappPostprocessorParam & dt);
}
