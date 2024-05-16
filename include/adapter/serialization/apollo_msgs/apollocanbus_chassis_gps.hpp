#pragma once
#include "apollo_msgs/msg/apollocanbus_chassis_gps.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusChassisGPS &msg) ;
    ApollocanbusChassisGPS from_json_ApollocanbusChassisGPS (nlohmann::json obj) ;
    template <>
    ApollocanbusChassisGPS from_json<ApollocanbusChassisGPS>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusChassisGPS &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusChassisGPS & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusChassisGPS & dt);
}
