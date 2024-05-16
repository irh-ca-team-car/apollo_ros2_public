#pragma once
#include "apollo_msgs/msg/apollocanbus_gear_command103.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearCommand103 &msg) ;
    ApollocanbusGearCommand103 from_json_ApollocanbusGearCommand103 (nlohmann::json obj) ;
    template <>
    ApollocanbusGearCommand103 from_json<ApollocanbusGearCommand103>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearCommand103 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearCommand103 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearCommand103 & dt);
}
