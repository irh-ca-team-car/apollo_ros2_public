#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_padding_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePaddingParameter &msg) ;
    ApolloperceptioninferencePaddingParameter from_json_ApolloperceptioninferencePaddingParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferencePaddingParameter from_json<ApolloperceptioninferencePaddingParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePaddingParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePaddingParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePaddingParameter & dt);
}
