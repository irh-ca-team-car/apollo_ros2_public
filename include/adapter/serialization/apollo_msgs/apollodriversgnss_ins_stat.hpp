#pragma once
#include "apollo_msgs/msg/apollodriversgnss_ins_stat.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssInsStat &msg) ;
    ApollodriversgnssInsStat from_json_ApollodriversgnssInsStat (nlohmann::json obj) ;
    template <>
    ApollodriversgnssInsStat from_json<ApollodriversgnssInsStat>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssInsStat &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssInsStat & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssInsStat & dt);
}
