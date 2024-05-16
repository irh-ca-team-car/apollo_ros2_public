#pragma once
#include "apollo_msgs/msg/apollohdmap_boundary_edge.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapBoundaryEdge &msg) ;
    ApollohdmapBoundaryEdge from_json_ApollohdmapBoundaryEdge (nlohmann::json obj) ;
    template <>
    ApollohdmapBoundaryEdge from_json<ApollohdmapBoundaryEdge>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapBoundaryEdge &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapBoundaryEdge & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapBoundaryEdge & dt);
}
