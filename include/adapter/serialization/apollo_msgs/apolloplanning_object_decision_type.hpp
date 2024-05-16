#pragma once
#include "apollo_msgs/msg/apolloplanning_object_decision_type.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision_typeobject_tag.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectDecisionType &msg) ;
    ApolloplanningObjectDecisionType from_json_ApolloplanningObjectDecisionType (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectDecisionType from_json<ApolloplanningObjectDecisionType>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectDecisionType &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectDecisionType & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectDecisionType & dt);
}
