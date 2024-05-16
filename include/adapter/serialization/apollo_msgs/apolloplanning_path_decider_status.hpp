#pragma once
#include "apollo_msgs/msg/apolloplanning_path_decider_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathDeciderStatus &msg) ;
    ApolloplanningPathDeciderStatus from_json_ApolloplanningPathDeciderStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningPathDeciderStatus from_json<ApolloplanningPathDeciderStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathDeciderStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathDeciderStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathDeciderStatus & dt);
}
