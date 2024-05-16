#pragma once
#include "apollo_msgs/msg/apollocanbus_aeb_frontwheelspeed353.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebFrontwheelspeed353 &msg) ;
    ApollocanbusAebFrontwheelspeed353 from_json_ApollocanbusAebFrontwheelspeed353 (nlohmann::json obj) ;
    template <>
    ApollocanbusAebFrontwheelspeed353 from_json<ApollocanbusAebFrontwheelspeed353>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebFrontwheelspeed353 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebFrontwheelspeed353 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebFrontwheelspeed353 & dt);
}
