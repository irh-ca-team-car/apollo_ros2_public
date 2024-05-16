#pragma once
#include "apollo_msgs/msg/apolloperception_debug_message.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_trajectory.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionDebugMessage &msg) ;
    ApolloperceptionDebugMessage from_json_ApolloperceptionDebugMessage (nlohmann::json obj) ;
    template <>
    ApolloperceptionDebugMessage from_json<ApolloperceptionDebugMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionDebugMessage &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionDebugMessage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionDebugMessage & dt);
}
