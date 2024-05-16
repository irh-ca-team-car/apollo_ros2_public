#pragma once
#include "apollo_msgs/msg/apollocanbus_wheel_speed_rpt7a.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWheelSpeedRpt7a &msg) ;
    ApollocanbusWheelSpeedRpt7a from_json_ApollocanbusWheelSpeedRpt7a (nlohmann::json obj) ;
    template <>
    ApollocanbusWheelSpeedRpt7a from_json<ApollocanbusWheelSpeedRpt7a>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWheelSpeedRpt7a &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWheelSpeedRpt7a & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWheelSpeedRpt7a & dt);
}
