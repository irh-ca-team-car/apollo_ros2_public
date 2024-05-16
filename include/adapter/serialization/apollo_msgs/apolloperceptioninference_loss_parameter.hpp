#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_loss_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLossParameter &msg) ;
    ApolloperceptioninferenceLossParameter from_json_ApolloperceptioninferenceLossParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceLossParameter from_json<ApolloperceptioninferenceLossParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLossParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLossParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLossParameter & dt);
}
