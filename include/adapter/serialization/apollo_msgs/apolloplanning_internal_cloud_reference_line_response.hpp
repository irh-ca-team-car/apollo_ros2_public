#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_cloud_reference_line_response.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalCloudReferenceLineResponse &msg) ;
    ApolloplanningInternalCloudReferenceLineResponse from_json_ApolloplanningInternalCloudReferenceLineResponse (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalCloudReferenceLineResponse from_json<ApolloplanningInternalCloudReferenceLineResponse>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalCloudReferenceLineResponse &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalCloudReferenceLineResponse & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalCloudReferenceLineResponse & dt);
}
