#pragma once
#include "apollo_msgs/msg/apolloplanning_overlap_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOverlapFeature &msg) ;
    ApolloplanningOverlapFeature from_json_ApolloplanningOverlapFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningOverlapFeature from_json<ApolloplanningOverlapFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOverlapFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOverlapFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOverlapFeature & dt);
}
