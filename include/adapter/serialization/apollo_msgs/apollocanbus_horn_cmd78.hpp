#pragma once
#include "apollo_msgs/msg/apollocanbus_horn_cmd78.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHornCmd78 &msg) ;
    ApollocanbusHornCmd78 from_json_ApollocanbusHornCmd78 (nlohmann::json obj) ;
    template <>
    ApollocanbusHornCmd78 from_json<ApollocanbusHornCmd78>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHornCmd78 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHornCmd78 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHornCmd78 & dt);
}
