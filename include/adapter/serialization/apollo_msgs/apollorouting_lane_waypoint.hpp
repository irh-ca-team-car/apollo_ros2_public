#pragma once
#include "apollo_msgs/msg/apollorouting_lane_waypoint.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingLaneWaypoint &msg) ;
    ApolloroutingLaneWaypoint from_json_ApolloroutingLaneWaypoint (nlohmann::json obj) ;
    template <>
    ApolloroutingLaneWaypoint from_json<ApolloroutingLaneWaypoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingLaneWaypoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingLaneWaypoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingLaneWaypoint & dt);
}
