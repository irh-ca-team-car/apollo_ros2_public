#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_spp_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSPPParameter &msg) ;
    ApolloperceptioninferenceSPPParameter from_json_ApolloperceptioninferenceSPPParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceSPPParameter from_json<ApolloperceptioninferenceSPPParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSPPParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSPPParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSPPParameter & dt);
}
