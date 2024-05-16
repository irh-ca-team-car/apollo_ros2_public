#pragma once
#include "apollo_msgs/msg/apollocontrol_simple_longitudinal_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolSimpleLongitudinalDebug &msg) ;
    ApollocontrolSimpleLongitudinalDebug from_json_ApollocontrolSimpleLongitudinalDebug (nlohmann::json obj) ;
    template <>
    ApollocontrolSimpleLongitudinalDebug from_json<ApollocontrolSimpleLongitudinalDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolSimpleLongitudinalDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolSimpleLongitudinalDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolSimpleLongitudinalDebug & dt);
}
