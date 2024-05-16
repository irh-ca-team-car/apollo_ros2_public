#pragma once
#include "apollo_msgs/msg/apollodriversgnss_ins.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point_llh.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssIns &msg) ;
    ApollodriversgnssIns from_json_ApollodriversgnssIns (nlohmann::json obj) ;
    template <>
    ApollodriversgnssIns from_json<ApollodriversgnssIns>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssIns &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssIns & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssIns & dt);
}
