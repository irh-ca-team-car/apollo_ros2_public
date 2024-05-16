#pragma once
#include "apollo_msgs/msg/apollorouting_routing_request.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_lane_waypoint.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_lane_segment.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_parking_space.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_parking_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingRoutingRequest &msg) ;
    ApolloroutingRoutingRequest from_json_ApolloroutingRoutingRequest (nlohmann::json obj) ;
    template <>
    ApolloroutingRoutingRequest from_json<ApolloroutingRoutingRequest>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingRoutingRequest &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingRoutingRequest & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingRoutingRequest & dt);
}
