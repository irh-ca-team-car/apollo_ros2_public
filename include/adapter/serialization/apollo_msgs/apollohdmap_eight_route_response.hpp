#pragma once
#include "apollo_msgs/msg/apollohdmap_eight_route_response.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapEightRouteResponse &msg) ;
    ApollohdmapEightRouteResponse from_json_ApollohdmapEightRouteResponse (nlohmann::json obj) ;
    template <>
    ApollohdmapEightRouteResponse from_json<ApollohdmapEightRouteResponse>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapEightRouteResponse &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapEightRouteResponse & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapEightRouteResponse & dt);
}
