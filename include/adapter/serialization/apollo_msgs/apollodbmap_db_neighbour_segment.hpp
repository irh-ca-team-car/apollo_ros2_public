#pragma once
#include "apollo_msgs/msg/apollodbmap_db_neighbour_segment.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBNeighbourSegment &msg) ;
    ApollodbmapDBNeighbourSegment from_json_ApollodbmapDBNeighbourSegment (nlohmann::json obj) ;
    template <>
    ApollodbmapDBNeighbourSegment from_json<ApollodbmapDBNeighbourSegment>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBNeighbourSegment &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBNeighbourSegment & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBNeighbourSegment & dt);
}
