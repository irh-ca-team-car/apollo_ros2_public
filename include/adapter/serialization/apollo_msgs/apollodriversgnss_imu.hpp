#pragma once
#include "apollo_msgs/msg/apollodriversgnss_imu.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssImu &msg) ;
    ApollodriversgnssImu from_json_ApollodriversgnssImu (nlohmann::json obj) ;
    template <>
    ApollodriversgnssImu from_json<ApollodriversgnssImu>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssImu &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssImu & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssImu & dt);
}
