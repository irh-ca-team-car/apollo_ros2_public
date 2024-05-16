#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_concat_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceConcatParameter &msg) ;
    ApolloperceptioninferenceConcatParameter from_json_ApolloperceptioninferenceConcatParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceConcatParameter from_json<ApolloperceptioninferenceConcatParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceConcatParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceConcatParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceConcatParameter & dt);
}
