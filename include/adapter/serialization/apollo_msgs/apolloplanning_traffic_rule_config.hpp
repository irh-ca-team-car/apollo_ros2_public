#pragma once
#include "apollo_msgs/msg/apolloplanning_traffic_rule_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_rule_configconfig.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficRuleConfig &msg) ;
    ApolloplanningTrafficRuleConfig from_json_ApolloplanningTrafficRuleConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningTrafficRuleConfig from_json<ApolloplanningTrafficRuleConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficRuleConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficRuleConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficRuleConfig & dt);
}
