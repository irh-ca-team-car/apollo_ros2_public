#pragma once
#include "apollo_msgs/msg/apollocanbus_horn_cmd11c.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHornCmd11c &msg) ;
    ApollocanbusHornCmd11c from_json_ApollocanbusHornCmd11c (nlohmann::json obj) ;
    template <>
    ApollocanbusHornCmd11c from_json<ApollocanbusHornCmd11c>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHornCmd11c &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHornCmd11c & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHornCmd11c & dt);
}
