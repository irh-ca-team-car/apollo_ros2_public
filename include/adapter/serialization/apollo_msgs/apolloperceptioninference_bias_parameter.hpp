#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_bias_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBiasParameter &msg) ;
    ApolloperceptioninferenceBiasParameter from_json_ApolloperceptioninferenceBiasParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceBiasParameter from_json<ApolloperceptioninferenceBiasParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBiasParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBiasParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBiasParameter & dt);
}
