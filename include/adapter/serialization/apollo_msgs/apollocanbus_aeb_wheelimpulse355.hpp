#pragma once
#include "apollo_msgs/msg/apollocanbus_aeb_wheelimpulse355.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebWheelimpulse355 &msg) ;
    ApollocanbusAebWheelimpulse355 from_json_ApollocanbusAebWheelimpulse355 (nlohmann::json obj) ;
    template <>
    ApollocanbusAebWheelimpulse355 from_json<ApollocanbusAebWheelimpulse355>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebWheelimpulse355 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebWheelimpulse355 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebWheelimpulse355 & dt);
}
