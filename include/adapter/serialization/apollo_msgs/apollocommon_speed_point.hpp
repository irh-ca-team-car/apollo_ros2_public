#pragma once
#include "apollo_msgs/msg/apollocommon_speed_point.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonSpeedPoint &msg) ;
    ApollocommonSpeedPoint from_json_ApollocommonSpeedPoint (nlohmann::json obj) ;
    template <>
    ApollocommonSpeedPoint from_json<ApollocommonSpeedPoint>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonSpeedPoint &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonSpeedPoint & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonSpeedPoint & dt);
}
