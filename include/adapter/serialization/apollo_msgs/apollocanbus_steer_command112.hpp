#pragma once
#include "apollo_msgs/msg/apollocanbus_steer_command112.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteerCommand112 &msg) ;
    ApollocanbusSteerCommand112 from_json_ApollocanbusSteerCommand112 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteerCommand112 from_json<ApollocanbusSteerCommand112>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteerCommand112 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteerCommand112 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteerCommand112 & dt);
}
