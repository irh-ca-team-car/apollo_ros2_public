#pragma once
#include "apollo_msgs/msg/apollorouting_edge.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingEdge &msg) ;
    ApolloroutingEdge from_json_ApolloroutingEdge (nlohmann::json obj) ;
    template <>
    ApolloroutingEdge from_json<ApolloroutingEdge>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingEdge &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingEdge & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingEdge & dt);
}
