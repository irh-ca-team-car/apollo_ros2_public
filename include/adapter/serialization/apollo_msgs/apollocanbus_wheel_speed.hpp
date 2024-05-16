#pragma once
#include "apollo_msgs/msg/apollocanbus_wheel_speed.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWheelSpeed &msg) ;
    ApollocanbusWheelSpeed from_json_ApollocanbusWheelSpeed (nlohmann::json obj) ;
    template <>
    ApollocanbusWheelSpeed from_json<ApollocanbusWheelSpeed>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWheelSpeed &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWheelSpeed & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWheelSpeed & dt);
}
