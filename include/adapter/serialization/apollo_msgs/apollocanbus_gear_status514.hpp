#pragma once
#include "apollo_msgs/msg/apollocanbus_gear_status514.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearStatus514 &msg) ;
    ApollocanbusGearStatus514 from_json_ApollocanbusGearStatus514 (nlohmann::json obj) ;
    template <>
    ApollocanbusGearStatus514 from_json<ApollocanbusGearStatus514>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearStatus514 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearStatus514 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearStatus514 & dt);
}
