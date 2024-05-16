#pragma once
#include "apollo_msgs/msg/apollocanbus_aeb_rearwheelspeed354.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebRearwheelspeed354 &msg) ;
    ApollocanbusAebRearwheelspeed354 from_json_ApollocanbusAebRearwheelspeed354 (nlohmann::json obj) ;
    template <>
    ApollocanbusAebRearwheelspeed354 from_json<ApollocanbusAebRearwheelspeed354>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebRearwheelspeed354 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebRearwheelspeed354 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebRearwheelspeed354 & dt);
}
