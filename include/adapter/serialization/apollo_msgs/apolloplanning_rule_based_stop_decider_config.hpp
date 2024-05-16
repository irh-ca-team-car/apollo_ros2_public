#pragma once
#include "apollo_msgs/msg/apolloplanning_rule_based_stop_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRuleBasedStopDeciderConfig &msg) ;
    ApolloplanningRuleBasedStopDeciderConfig from_json_ApolloplanningRuleBasedStopDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningRuleBasedStopDeciderConfig from_json<ApolloplanningRuleBasedStopDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRuleBasedStopDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRuleBasedStopDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRuleBasedStopDeciderConfig & dt);
}
