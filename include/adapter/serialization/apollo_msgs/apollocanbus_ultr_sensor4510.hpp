#pragma once
#include "apollo_msgs/msg/apollocanbus_ultr_sensor4510.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor4510 &msg) ;
    ApollocanbusUltrSensor4510 from_json_ApollocanbusUltrSensor4510 (nlohmann::json obj) ;
    template <>
    ApollocanbusUltrSensor4510 from_json<ApollocanbusUltrSensor4510>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor4510 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor4510 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor4510 & dt);
}
