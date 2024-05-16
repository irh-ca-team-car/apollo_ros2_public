#pragma once
#include "apollo_msgs/msg/apollocommon_latency_record_map.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_record.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyRecordMap &msg) ;
    ApollocommonLatencyRecordMap from_json_ApollocommonLatencyRecordMap (nlohmann::json obj) ;
    template <>
    ApollocommonLatencyRecordMap from_json<ApollocommonLatencyRecordMap>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyRecordMap &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyRecordMap & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyRecordMap & dt);
}
