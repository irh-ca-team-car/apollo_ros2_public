#pragma once
#include "apollo_msgs/msg/apollocanbus_wheelspeed_report506.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWheelspeedReport506 &msg) ;
    ApollocanbusWheelspeedReport506 from_json_ApollocanbusWheelspeedReport506 (nlohmann::json obj) ;
    template <>
    ApollocanbusWheelspeedReport506 from_json<ApollocanbusWheelspeedReport506>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWheelspeedReport506 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWheelspeedReport506 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWheelspeedReport506 & dt);
}
