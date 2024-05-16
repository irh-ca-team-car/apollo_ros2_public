#pragma once
#include "apollo_msgs/msg/apollorouting_graph.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_node.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_edge.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingGraph &msg) ;
    ApolloroutingGraph from_json_ApolloroutingGraph (nlohmann::json obj) ;
    template <>
    ApolloroutingGraph from_json<ApolloroutingGraph>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingGraph &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingGraph & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingGraph & dt);
}
