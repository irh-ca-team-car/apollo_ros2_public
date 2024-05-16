#pragma once
#include "apollo_msgs/msg/apollocanbus_vin_rpt414.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVinRpt414 &msg) ;
    ApollocanbusVinRpt414 from_json_ApollocanbusVinRpt414 (nlohmann::json obj) ;
    template <>
    ApollocanbusVinRpt414 from_json<ApollocanbusVinRpt414>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVinRpt414 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVinRpt414 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVinRpt414 & dt);
}
