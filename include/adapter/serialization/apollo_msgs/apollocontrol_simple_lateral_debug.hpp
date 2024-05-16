#pragma once
#include "apollo_msgs/msg/apollocontrol_simple_lateral_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_mrac_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolSimpleLateralDebug &msg) ;
    ApollocontrolSimpleLateralDebug from_json_ApollocontrolSimpleLateralDebug (nlohmann::json obj) ;
    template <>
    ApollocontrolSimpleLateralDebug from_json<ApollocontrolSimpleLateralDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolSimpleLateralDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolSimpleLateralDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolSimpleLateralDebug & dt);
}
