#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_motioncommandfeedback122.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcMotioncommandfeedback122 &msg) ;
    ApollocanbusLlcMotioncommandfeedback122 from_json_ApollocanbusLlcMotioncommandfeedback122 (nlohmann::json obj) ;
    template <>
    ApollocanbusLlcMotioncommandfeedback122 from_json<ApollocanbusLlcMotioncommandfeedback122>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcMotioncommandfeedback122 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcMotioncommandfeedback122 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcMotioncommandfeedback122 & dt);
}
