#pragma once
#include "apollo_msgs/msg/apollocontrol_latency_stats.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLatencyStats &msg) ;
    ApollocontrolLatencyStats from_json_ApollocontrolLatencyStats (nlohmann::json obj) ;
    template <>
    ApollocontrolLatencyStats from_json<ApollocontrolLatencyStats>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLatencyStats &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLatencyStats & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLatencyStats & dt);
}
