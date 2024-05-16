#pragma once
#include "apollo_msgs/msg/apolloplanning_routing_response_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_road_segment.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_measurement.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRoutingResponseFeature &msg) ;
    ApolloplanningRoutingResponseFeature from_json_ApolloplanningRoutingResponseFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningRoutingResponseFeature from_json<ApolloplanningRoutingResponseFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRoutingResponseFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRoutingResponseFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRoutingResponseFeature & dt);
}
