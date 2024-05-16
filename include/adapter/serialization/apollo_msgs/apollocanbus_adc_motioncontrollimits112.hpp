#pragma once
#include "apollo_msgs/msg/apollocanbus_adc_motioncontrollimits112.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdcMotioncontrollimits112 &msg) ;
    ApollocanbusAdcMotioncontrollimits112 from_json_ApollocanbusAdcMotioncontrollimits112 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdcMotioncontrollimits112 from_json<ApollocanbusAdcMotioncontrollimits112>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdcMotioncontrollimits112 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdcMotioncontrollimits112 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdcMotioncontrollimits112 & dt);
}
