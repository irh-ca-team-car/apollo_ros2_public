#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_b_box_reg_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBBoxRegParameter &msg) ;
    ApolloperceptioninferenceBBoxRegParameter from_json_ApolloperceptioninferenceBBoxRegParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceBBoxRegParameter from_json<ApolloperceptioninferenceBBoxRegParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBBoxRegParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBBoxRegParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBBoxRegParameter & dt);
}
