#pragma once
#include "apollo_msgs/msg/apollocanbus_gear_command114.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearCommand114 &msg) ;
    ApollocanbusGearCommand114 from_json_ApollocanbusGearCommand114 (nlohmann::json obj) ;
    template <>
    ApollocanbusGearCommand114 from_json<ApollocanbusGearCommand114>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearCommand114 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearCommand114 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearCommand114 & dt);
}
