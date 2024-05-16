#pragma once
#include "apollo_msgs/msg/apollocanbus_ultr_sensor2508.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor2508 &msg) ;
    ApollocanbusUltrSensor2508 from_json_ApollocanbusUltrSensor2508 (nlohmann::json obj) ;
    template <>
    ApollocanbusUltrSensor2508 from_json<ApollocanbusUltrSensor2508>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor2508 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor2508 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor2508 & dt);
}
