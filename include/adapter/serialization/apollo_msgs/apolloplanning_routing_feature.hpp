#pragma once
#include "apollo_msgs/msg/apolloplanning_routing_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_routing_response_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRoutingFeature &msg) ;
    ApolloplanningRoutingFeature from_json_ApolloplanningRoutingFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningRoutingFeature from_json<ApolloplanningRoutingFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRoutingFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRoutingFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRoutingFeature & dt);
}
