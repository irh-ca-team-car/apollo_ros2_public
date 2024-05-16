#pragma once
#include "apollo_msgs/msg/apolloplanning_main_emergency_stop.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_main_emergency_stoptask.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainEmergencyStop &msg) ;
    ApolloplanningMainEmergencyStop from_json_ApolloplanningMainEmergencyStop (nlohmann::json obj) ;
    template <>
    ApolloplanningMainEmergencyStop from_json<ApolloplanningMainEmergencyStop>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainEmergencyStop &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainEmergencyStop & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainEmergencyStop & dt);
}
