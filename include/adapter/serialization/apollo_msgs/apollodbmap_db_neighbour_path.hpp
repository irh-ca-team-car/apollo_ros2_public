#pragma once
#include "apollo_msgs/msg/apollodbmap_db_neighbour_path.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodbmap_db_neighbour_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBNeighbourPath &msg) ;
    ApollodbmapDBNeighbourPath from_json_ApollodbmapDBNeighbourPath (nlohmann::json obj) ;
    template <>
    ApollodbmapDBNeighbourPath from_json<ApollodbmapDBNeighbourPath>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBNeighbourPath &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBNeighbourPath & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBNeighbourPath & dt);
}
