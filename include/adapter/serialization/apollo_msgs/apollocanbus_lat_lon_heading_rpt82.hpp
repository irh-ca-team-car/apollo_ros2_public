#pragma once
#include "apollo_msgs/msg/apollocanbus_lat_lon_heading_rpt82.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLatLonHeadingRpt82 &msg) ;
    ApollocanbusLatLonHeadingRpt82 from_json_ApollocanbusLatLonHeadingRpt82 (nlohmann::json obj) ;
    template <>
    ApollocanbusLatLonHeadingRpt82 from_json<ApollocanbusLatLonHeadingRpt82>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLatLonHeadingRpt82 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLatLonHeadingRpt82 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLatLonHeadingRpt82 & dt);
}
