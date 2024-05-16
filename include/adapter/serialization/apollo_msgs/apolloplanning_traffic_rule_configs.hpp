#pragma once
#include "apollo_msgs/msg/apolloplanning_traffic_rule_configs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_rule_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficRuleConfigs &msg) ;
    ApolloplanningTrafficRuleConfigs from_json_ApolloplanningTrafficRuleConfigs (nlohmann::json obj) ;
    template <>
    ApolloplanningTrafficRuleConfigs from_json<ApolloplanningTrafficRuleConfigs>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficRuleConfigs &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficRuleConfigs & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficRuleConfigs & dt);
}
