#pragma once
#include "apollo_msgs/msg/apolloplanning_yield_sign_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningYieldSignStatus &msg) ;
    ApolloplanningYieldSignStatus from_json_ApolloplanningYieldSignStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningYieldSignStatus from_json<ApolloplanningYieldSignStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningYieldSignStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningYieldSignStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningYieldSignStatus & dt);
}
