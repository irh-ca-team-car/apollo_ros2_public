#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_cloud_reference_line_routing_request.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_routing_response.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalCloudReferenceLineRoutingRequest &msg) ;
    ApolloplanningInternalCloudReferenceLineRoutingRequest from_json_ApolloplanningInternalCloudReferenceLineRoutingRequest (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalCloudReferenceLineRoutingRequest from_json<ApolloplanningInternalCloudReferenceLineRoutingRequest>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalCloudReferenceLineRoutingRequest &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalCloudReferenceLineRoutingRequest & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalCloudReferenceLineRoutingRequest & dt);
}
