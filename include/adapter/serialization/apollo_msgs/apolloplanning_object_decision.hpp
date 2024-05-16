#pragma once
#include "apollo_msgs/msg/apolloplanning_object_decision.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectDecision &msg) ;
    ApolloplanningObjectDecision from_json_ApolloplanningObjectDecision (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectDecision from_json<ApolloplanningObjectDecision>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectDecision &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectDecision & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectDecision & dt);
}
