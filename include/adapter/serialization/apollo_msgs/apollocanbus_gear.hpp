#pragma once
#include "apollo_msgs/msg/apollocanbus_gear.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGear &msg) ;
    ApollocanbusGear from_json_ApollocanbusGear (nlohmann::json obj) ;
    template <>
    ApollocanbusGear from_json<ApollocanbusGear>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGear &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGear & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGear & dt);
}
