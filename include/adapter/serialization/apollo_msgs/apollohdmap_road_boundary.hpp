#pragma once
#include "apollo_msgs/msg/apollohdmap_road_boundary.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_boundary_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRoadBoundary &msg) ;
    ApollohdmapRoadBoundary from_json_ApollohdmapRoadBoundary (nlohmann::json obj) ;
    template <>
    ApollohdmapRoadBoundary from_json<ApollohdmapRoadBoundary>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRoadBoundary &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRoadBoundary & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRoadBoundary & dt);
}
