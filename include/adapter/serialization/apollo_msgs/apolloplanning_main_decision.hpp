#pragma once
#include "apollo_msgs/msg/apolloplanning_main_decision.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_main_decisiontask.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_target_lane.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainDecision &msg) ;
    ApolloplanningMainDecision from_json_ApolloplanningMainDecision (nlohmann::json obj) ;
    template <>
    ApolloplanningMainDecision from_json<ApolloplanningMainDecision>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainDecision &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainDecision & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainDecision & dt);
}
