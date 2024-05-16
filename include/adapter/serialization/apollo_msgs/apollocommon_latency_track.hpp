#pragma once
#include "apollo_msgs/msg/apollocommon_latency_track.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyTrack &msg) ;
    ApollocommonLatencyTrack from_json_ApollocommonLatencyTrack (nlohmann::json obj) ;
    template <>
    ApollocommonLatencyTrack from_json<ApollocommonLatencyTrack>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyTrack &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyTrack & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyTrack & dt);
}
