#pragma once
#include "apollo_msgs/msg/apollocanbus_ultr_sensor1507.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor1507 &msg) ;
    ApollocanbusUltrSensor1507 from_json_ApollocanbusUltrSensor1507 (nlohmann::json obj) ;
    template <>
    ApollocanbusUltrSensor1507 from_json<ApollocanbusUltrSensor1507>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor1507 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor1507 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor1507 & dt);
}
