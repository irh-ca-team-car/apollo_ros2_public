#pragma once
#include "apollo_msgs/msg/apolloplanning_latency_stats.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_task_stats.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLatencyStats &msg) ;
    ApolloplanningLatencyStats from_json_ApolloplanningLatencyStats (nlohmann::json obj) ;
    template <>
    ApolloplanningLatencyStats from_json<ApolloplanningLatencyStats>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLatencyStats &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLatencyStats & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLatencyStats & dt);
}
