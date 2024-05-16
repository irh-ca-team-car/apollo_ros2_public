#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_crop_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceCropParameter &msg) ;
    ApolloperceptioninferenceCropParameter from_json_ApolloperceptioninferenceCropParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceCropParameter from_json<ApolloperceptioninferenceCropParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceCropParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceCropParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceCropParameter & dt);
}
