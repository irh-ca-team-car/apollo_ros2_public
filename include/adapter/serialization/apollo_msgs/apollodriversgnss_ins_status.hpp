#pragma once
#include "apollo_msgs/msg/apollodriversgnss_ins_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssInsStatus &msg) ;
    ApollodriversgnssInsStatus from_json_ApollodriversgnssInsStatus (nlohmann::json obj) ;
    template <>
    ApollodriversgnssInsStatus from_json<ApollodriversgnssInsStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssInsStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssInsStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssInsStatus & dt);
}
