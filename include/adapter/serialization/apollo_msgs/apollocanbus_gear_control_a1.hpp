#pragma once
#include "apollo_msgs/msg/apollocanbus_gear_control_a1.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearControlA1 &msg) ;
    ApollocanbusGearControlA1 from_json_ApollocanbusGearControlA1 (nlohmann::json obj) ;
    template <>
    ApollocanbusGearControlA1 from_json<ApollocanbusGearControlA1>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearControlA1 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearControlA1 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearControlA1 & dt);
}
