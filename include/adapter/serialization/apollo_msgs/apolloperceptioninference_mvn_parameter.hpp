#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_mvn_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceMVNParameter &msg) ;
    ApolloperceptioninferenceMVNParameter from_json_ApolloperceptioninferenceMVNParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceMVNParameter from_json<ApolloperceptioninferenceMVNParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceMVNParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceMVNParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceMVNParameter & dt);
}
