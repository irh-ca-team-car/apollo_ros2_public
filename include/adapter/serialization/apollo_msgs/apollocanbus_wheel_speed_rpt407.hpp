#pragma once
#include "apollo_msgs/msg/apollocanbus_wheel_speed_rpt407.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWheelSpeedRpt407 &msg) ;
    ApollocanbusWheelSpeedRpt407 from_json_ApollocanbusWheelSpeedRpt407 (nlohmann::json obj) ;
    template <>
    ApollocanbusWheelSpeedRpt407 from_json<ApollocanbusWheelSpeedRpt407>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWheelSpeedRpt407 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWheelSpeedRpt407 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWheelSpeedRpt407 & dt);
}
