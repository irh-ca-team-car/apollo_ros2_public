#pragma once
#include "apollo_msgs/msg/apollocanbus_wiper_rpt234.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWiperRpt234 &msg) ;
    ApollocanbusWiperRpt234 from_json_ApollocanbusWiperRpt234 (nlohmann::json obj) ;
    template <>
    ApollocanbusWiperRpt234 from_json<ApollocanbusWiperRpt234>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWiperRpt234 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWiperRpt234 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWiperRpt234 & dt);
}
