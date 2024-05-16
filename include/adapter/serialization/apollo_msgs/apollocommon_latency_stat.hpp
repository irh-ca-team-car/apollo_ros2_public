#pragma once
#include "apollo_msgs/msg/apollocommon_latency_stat.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyStat &msg) ;
    ApollocommonLatencyStat from_json_ApollocommonLatencyStat (nlohmann::json obj) ;
    template <>
    ApollocommonLatencyStat from_json<ApollocommonLatencyStat>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyStat &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyStat & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyStat & dt);
}
