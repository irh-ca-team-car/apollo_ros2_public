#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_cloud_reference_line_request.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_lane_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalCloudReferenceLineRequest &msg) ;
    ApolloplanningInternalCloudReferenceLineRequest from_json_ApolloplanningInternalCloudReferenceLineRequest (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalCloudReferenceLineRequest from_json<ApolloplanningInternalCloudReferenceLineRequest>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalCloudReferenceLineRequest &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalCloudReferenceLineRequest & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalCloudReferenceLineRequest & dt);
}
