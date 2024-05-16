#pragma once
#include "apollo_msgs/msg/apollocanbus_ultr_sensor3509.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor3509 &msg) ;
    ApollocanbusUltrSensor3509 from_json_ApollocanbusUltrSensor3509 (nlohmann::json obj) ;
    template <>
    ApollocanbusUltrSensor3509 from_json<ApollocanbusUltrSensor3509>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor3509 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor3509 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor3509 & dt);
}
