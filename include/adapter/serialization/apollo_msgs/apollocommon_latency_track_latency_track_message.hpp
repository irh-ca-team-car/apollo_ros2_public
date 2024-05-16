#pragma once
#include "apollo_msgs/msg/apollocommon_latency_track_latency_track_message.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_latency_stat.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyTrackLatencyTrackMessage &msg) ;
    ApollocommonLatencyTrackLatencyTrackMessage from_json_ApollocommonLatencyTrackLatencyTrackMessage (nlohmann::json obj) ;
    template <>
    ApollocommonLatencyTrackLatencyTrackMessage from_json<ApollocommonLatencyTrackLatencyTrackMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyTrackLatencyTrackMessage &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyTrackLatencyTrackMessage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyTrackLatencyTrackMessage & dt);
}
