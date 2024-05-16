#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_p_re_lu_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePReLUParameter &msg) ;
    ApolloperceptioninferencePReLUParameter from_json_ApolloperceptioninferencePReLUParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferencePReLUParameter from_json<ApolloperceptioninferencePReLUParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePReLUParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePReLUParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePReLUParameter & dt);
}
