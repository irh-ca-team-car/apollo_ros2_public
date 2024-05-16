#pragma once
#include "apollo_msgs/msg/apollorouting_routing_response.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_road_segment.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_measurement.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_routing_request.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_status_pb.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingRoutingResponse &msg) ;
    ApolloroutingRoutingResponse from_json_ApolloroutingRoutingResponse (nlohmann::json obj) ;
    template <>
    ApolloroutingRoutingResponse from_json<ApolloroutingRoutingResponse>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingRoutingResponse &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingRoutingResponse & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingRoutingResponse & dt);
}
