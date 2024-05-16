#pragma once
#include "apollo_msgs/msg/apollocontrol_input_debug.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolInputDebug &msg) ;
    ApollocontrolInputDebug from_json_ApollocontrolInputDebug (nlohmann::json obj) ;
    template <>
    ApollocontrolInputDebug from_json<ApollocontrolInputDebug>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolInputDebug &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolInputDebug & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolInputDebug & dt);
}
