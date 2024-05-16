#pragma once
#include "apollo_msgs/msg/apollocanbus_occupancy_rpt415.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusOccupancyRpt415 &msg) ;
    ApollocanbusOccupancyRpt415 from_json_ApollocanbusOccupancyRpt415 (nlohmann::json obj) ;
    template <>
    ApollocanbusOccupancyRpt415 from_json<ApollocanbusOccupancyRpt415>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusOccupancyRpt415 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusOccupancyRpt415 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusOccupancyRpt415 & dt);
}
