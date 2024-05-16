#pragma once
#include "apollo_msgs/msg/apollorouting_node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_curve_range.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingNode &msg) ;
    ApolloroutingNode from_json_ApolloroutingNode (nlohmann::json obj) ;
    template <>
    ApolloroutingNode from_json<ApolloroutingNode>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingNode &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingNode & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingNode & dt);
}
