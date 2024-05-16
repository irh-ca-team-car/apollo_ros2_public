#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_object_template_meta.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_object_template.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraObjectTemplateMeta &msg) ;
    ApolloperceptioncameraObjectTemplateMeta from_json_ApolloperceptioncameraObjectTemplateMeta (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraObjectTemplateMeta from_json<ApolloperceptioncameraObjectTemplateMeta>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraObjectTemplateMeta &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraObjectTemplateMeta & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraObjectTemplateMeta & dt);
}
