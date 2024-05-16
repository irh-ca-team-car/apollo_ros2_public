#pragma once
#include "apollo_msgs/msg/apolloplanning_creep_decider_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCreepDeciderStatus &msg) ;
    ApolloplanningCreepDeciderStatus from_json_ApolloplanningCreepDeciderStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningCreepDeciderStatus from_json<ApolloplanningCreepDeciderStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCreepDeciderStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCreepDeciderStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCreepDeciderStatus & dt);
}
