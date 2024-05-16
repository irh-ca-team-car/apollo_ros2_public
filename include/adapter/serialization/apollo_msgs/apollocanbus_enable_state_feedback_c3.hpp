#pragma once
#include "apollo_msgs/msg/apollocanbus_enable_state_feedback_c3.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEnableStateFeedbackC3 &msg) ;
    ApollocanbusEnableStateFeedbackC3 from_json_ApollocanbusEnableStateFeedbackC3 (nlohmann::json obj) ;
    template <>
    ApollocanbusEnableStateFeedbackC3 from_json<ApollocanbusEnableStateFeedbackC3>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEnableStateFeedbackC3 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEnableStateFeedbackC3 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEnableStateFeedbackC3 & dt);
}
