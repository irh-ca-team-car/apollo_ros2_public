#pragma once
#include "apollo_msgs/msg/apollomonitor_system_statuscomponents.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollomonitor_component.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorSystemStatuscomponents &msg) ;
    ApollomonitorSystemStatuscomponents from_json_ApollomonitorSystemStatuscomponents (nlohmann::json obj) ;
    template <>
    ApollomonitorSystemStatuscomponents from_json<ApollomonitorSystemStatuscomponents>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorSystemStatuscomponents &dt);
    std::ostream & operator<<(std::ostream & os, const ApollomonitorSystemStatuscomponents & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorSystemStatuscomponents & dt);
}
