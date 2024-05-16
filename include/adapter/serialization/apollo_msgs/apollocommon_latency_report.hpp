#pragma once
#include "apollo_msgs/msg/apollocommon_latency_report.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_track.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyReport &msg) ;
    ApollocommonLatencyReport from_json_ApollocommonLatencyReport (nlohmann::json obj) ;
    template <>
    ApollocommonLatencyReport from_json<ApollocommonLatencyReport>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyReport &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyReport & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyReport & dt);
}
