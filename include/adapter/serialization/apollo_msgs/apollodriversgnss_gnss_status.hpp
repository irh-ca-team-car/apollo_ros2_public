#pragma once
#include "apollo_msgs/msg/apollodriversgnss_gnss_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGnssStatus &msg) ;
    ApollodriversgnssGnssStatus from_json_ApollodriversgnssGnssStatus (nlohmann::json obj) ;
    template <>
    ApollodriversgnssGnssStatus from_json<ApollodriversgnssGnssStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGnssStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGnssStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGnssStatus & dt);
}
