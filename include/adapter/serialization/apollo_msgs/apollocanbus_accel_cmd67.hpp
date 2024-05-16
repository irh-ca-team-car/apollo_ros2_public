#pragma once
#include "apollo_msgs/msg/apollocanbus_accel_cmd67.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAccelCmd67 &msg) ;
    ApollocanbusAccelCmd67 from_json_ApollocanbusAccelCmd67 (nlohmann::json obj) ;
    template <>
    ApollocanbusAccelCmd67 from_json<ApollocanbusAccelCmd67>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAccelCmd67 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAccelCmd67 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAccelCmd67 & dt);
}
