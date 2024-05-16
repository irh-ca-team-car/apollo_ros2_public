#pragma once
#include "apollo_msgs/msg/apolloguardian_guardian_command.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_control_command.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloguardianGuardianCommand &msg) ;
    ApolloguardianGuardianCommand from_json_ApolloguardianGuardianCommand (nlohmann::json obj) ;
    template <>
    ApolloguardianGuardianCommand from_json<ApolloguardianGuardianCommand>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloguardianGuardianCommand &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloguardianGuardianCommand & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloguardianGuardianCommand & dt);
}
