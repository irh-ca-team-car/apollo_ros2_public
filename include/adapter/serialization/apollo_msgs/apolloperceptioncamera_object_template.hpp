#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_object_template.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_dim.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraObjectTemplate &msg) ;
    ApolloperceptioncameraObjectTemplate from_json_ApolloperceptioncameraObjectTemplate (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraObjectTemplate from_json<ApolloperceptioncameraObjectTemplate>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraObjectTemplate &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraObjectTemplate & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraObjectTemplate & dt);
}
