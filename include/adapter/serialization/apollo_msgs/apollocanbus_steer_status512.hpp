#pragma once
#include "apollo_msgs/msg/apollocanbus_steer_status512.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteerStatus512 &msg) ;
    ApollocanbusSteerStatus512 from_json_ApollocanbusSteerStatus512 (nlohmann::json obj) ;
    template <>
    ApollocanbusSteerStatus512 from_json<ApollocanbusSteerStatus512>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteerStatus512 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteerStatus512 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteerStatus512 & dt);
}
