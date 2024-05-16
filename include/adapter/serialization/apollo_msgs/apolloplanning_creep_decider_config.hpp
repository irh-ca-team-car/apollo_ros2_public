#pragma once
#include "apollo_msgs/msg/apolloplanning_creep_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCreepDeciderConfig &msg) ;
    ApolloplanningCreepDeciderConfig from_json_ApolloplanningCreepDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningCreepDeciderConfig from_json<ApolloplanningCreepDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCreepDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCreepDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCreepDeciderConfig & dt);
}
