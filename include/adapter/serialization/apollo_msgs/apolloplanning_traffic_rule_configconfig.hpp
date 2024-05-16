#pragma once
#include "apollo_msgs/msg/apolloplanning_traffic_rule_configconfig.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_backside_vehicle_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_crosswalk_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_destination_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_keep_clear_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_reference_line_end_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_rerouting_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_stop_sign_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_yield_sign_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficRuleConfigconfig &msg) ;
    ApolloplanningTrafficRuleConfigconfig from_json_ApolloplanningTrafficRuleConfigconfig (nlohmann::json obj) ;
    template <>
    ApolloplanningTrafficRuleConfigconfig from_json<ApolloplanningTrafficRuleConfigconfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficRuleConfigconfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficRuleConfigconfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficRuleConfigconfig & dt);
}
