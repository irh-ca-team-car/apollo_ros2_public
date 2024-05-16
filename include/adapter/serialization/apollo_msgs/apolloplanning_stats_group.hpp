#pragma once
#include "apollo_msgs/msg/apolloplanning_stats_group.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStatsGroup &msg) ;
    ApolloplanningStatsGroup from_json_ApolloplanningStatsGroup (nlohmann::json obj) ;
    template <>
    ApolloplanningStatsGroup from_json<ApolloplanningStatsGroup>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStatsGroup &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStatsGroup & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStatsGroup & dt);
}
