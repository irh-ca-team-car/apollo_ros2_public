#pragma once
#include "apollo_msgs/msg/apollodriversgnss_stream_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssStreamStatus &msg) ;
    ApollodriversgnssStreamStatus from_json_ApollodriversgnssStreamStatus (nlohmann::json obj) ;
    template <>
    ApollodriversgnssStreamStatus from_json<ApollodriversgnssStreamStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssStreamStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssStreamStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssStreamStatus & dt);
}
