#pragma once
#include "apollo_msgs/msg/apolloplanning_rerouting_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_routing_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningReroutingStatus &msg) ;
    ApolloplanningReroutingStatus from_json_ApolloplanningReroutingStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningReroutingStatus from_json<ApolloplanningReroutingStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningReroutingStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningReroutingStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningReroutingStatus & dt);
}
