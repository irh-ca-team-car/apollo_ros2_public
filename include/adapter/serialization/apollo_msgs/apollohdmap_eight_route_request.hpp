#pragma once
#include "apollo_msgs/msg/apollohdmap_eight_route_request.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapEightRouteRequest &msg) ;
    ApollohdmapEightRouteRequest from_json_ApollohdmapEightRouteRequest (nlohmann::json obj) ;
    template <>
    ApollohdmapEightRouteRequest from_json<ApollohdmapEightRouteRequest>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapEightRouteRequest &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapEightRouteRequest & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapEightRouteRequest & dt);
}
