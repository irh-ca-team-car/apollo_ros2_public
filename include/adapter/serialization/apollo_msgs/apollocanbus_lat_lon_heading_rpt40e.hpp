#pragma once
#include "apollo_msgs/msg/apollocanbus_lat_lon_heading_rpt40e.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLatLonHeadingRpt40e &msg) ;
    ApollocanbusLatLonHeadingRpt40e from_json_ApollocanbusLatLonHeadingRpt40e (nlohmann::json obj) ;
    template <>
    ApollocanbusLatLonHeadingRpt40e from_json<ApollocanbusLatLonHeadingRpt40e>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLatLonHeadingRpt40e &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLatLonHeadingRpt40e & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLatLonHeadingRpt40e & dt);
}
