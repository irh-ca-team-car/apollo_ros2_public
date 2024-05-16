#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_speed_plan.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_speed_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSpeedPlan &msg) ;
    ApolloplanningInternalSpeedPlan from_json_ApolloplanningInternalSpeedPlan (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalSpeedPlan from_json<ApolloplanningInternalSpeedPlan>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSpeedPlan &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSpeedPlan & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSpeedPlan & dt);
}
