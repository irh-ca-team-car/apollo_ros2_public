#pragma once
#include "apollo_msgs/msg/apollodrivers_ldw_roadway.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_lane.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwRoadway &msg) ;
    ApollodriversLdwRoadway from_json_ApollodriversLdwRoadway (nlohmann::json obj) ;
    template <>
    ApollodriversLdwRoadway from_json<ApollodriversLdwRoadway>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwRoadway &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwRoadway & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwRoadway & dt);
}
