#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_decision_tag.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalDecisionTag &msg) ;
    ApolloplanningInternalDecisionTag from_json_ApolloplanningInternalDecisionTag (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalDecisionTag from_json<ApolloplanningInternalDecisionTag>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalDecisionTag &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalDecisionTag & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalDecisionTag & dt);
}
