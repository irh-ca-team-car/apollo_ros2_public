#pragma once
#include "apollo_msgs/msg/apollocanbus_adc_motioncontrol110.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdcMotioncontrol110 &msg) ;
    ApollocanbusAdcMotioncontrol110 from_json_ApollocanbusAdcMotioncontrol110 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdcMotioncontrol110 from_json<ApollocanbusAdcMotioncontrol110>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdcMotioncontrol110 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdcMotioncontrol110 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdcMotioncontrol110 & dt);
}
