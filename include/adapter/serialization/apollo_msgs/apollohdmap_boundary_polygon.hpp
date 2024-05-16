#pragma once
#include "apollo_msgs/msg/apollohdmap_boundary_polygon.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_boundary_edge.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapBoundaryPolygon &msg) ;
    ApollohdmapBoundaryPolygon from_json_ApollohdmapBoundaryPolygon (nlohmann::json obj) ;
    template <>
    ApollohdmapBoundaryPolygon from_json<ApollohdmapBoundaryPolygon>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapBoundaryPolygon &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapBoundaryPolygon & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapBoundaryPolygon & dt);
}
