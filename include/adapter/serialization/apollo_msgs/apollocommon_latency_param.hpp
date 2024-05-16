#pragma once
#include "apollo_msgs/msg/apollocommon_latency_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyParam &msg) ;
    ApollocommonLatencyParam from_json_ApollocommonLatencyParam (nlohmann::json obj) ;
    template <>
    ApollocommonLatencyParam from_json<ApollocommonLatencyParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyParam & dt);
}
