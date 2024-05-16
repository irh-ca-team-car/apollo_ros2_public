#pragma once
#include "apollo_msgs/msg/apollocanbus_horn_rpt21c.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHornRpt21c &msg) ;
    ApollocanbusHornRpt21c from_json_ApollocanbusHornRpt21c (nlohmann::json obj) ;
    template <>
    ApollocanbusHornRpt21c from_json<ApollocanbusHornRpt21c>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHornRpt21c &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHornRpt21c & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHornRpt21c & dt);
}
