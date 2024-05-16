#pragma once
#include "apollo_msgs/msg/apollocanbus_ultr_sensor5511.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor5511 &msg) ;
    ApollocanbusUltrSensor5511 from_json_ApollocanbusUltrSensor5511 (nlohmann::json obj) ;
    template <>
    ApollocanbusUltrSensor5511 from_json<ApollocanbusUltrSensor5511>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor5511 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor5511 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor5511 & dt);
}
