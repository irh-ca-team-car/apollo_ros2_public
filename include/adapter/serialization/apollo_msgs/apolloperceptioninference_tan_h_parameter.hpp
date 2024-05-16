#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_tan_h_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceTanHParameter &msg) ;
    ApolloperceptioninferenceTanHParameter from_json_ApolloperceptioninferenceTanHParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceTanHParameter from_json<ApolloperceptioninferenceTanHParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceTanHParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceTanHParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceTanHParameter & dt);
}
