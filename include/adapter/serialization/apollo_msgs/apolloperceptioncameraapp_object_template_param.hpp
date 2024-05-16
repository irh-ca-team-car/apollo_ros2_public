#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_object_template_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_plugin_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappObjectTemplateParam &msg) ;
    ApolloperceptioncameraappObjectTemplateParam from_json_ApolloperceptioncameraappObjectTemplateParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappObjectTemplateParam from_json<ApolloperceptioncameraappObjectTemplateParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappObjectTemplateParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappObjectTemplateParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappObjectTemplateParam & dt);
}
