#pragma once
#include "apollo_msgs/msg/apolloplanning_object_decisions.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectDecisions &msg) ;
    ApolloplanningObjectDecisions from_json_ApolloplanningObjectDecisions (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectDecisions from_json<ApolloplanningObjectDecisions>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectDecisions &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectDecisions & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectDecisions & dt);
}
