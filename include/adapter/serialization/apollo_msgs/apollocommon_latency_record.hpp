#pragma once
#include "apollo_msgs/msg/apollocommon_latency_record.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyRecord &msg) ;
    ApollocommonLatencyRecord from_json_ApollocommonLatencyRecord (nlohmann::json obj) ;
    template <>
    ApollocommonLatencyRecord from_json<ApollocommonLatencyRecord>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyRecord &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyRecord & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyRecord & dt);
}
