#pragma once
#include "apollo_msgs/msg/apollocommonmonitor_monitor_message_item.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonmonitorMonitorMessageItem &msg) ;
    ApollocommonmonitorMonitorMessageItem from_json_ApollocommonmonitorMonitorMessageItem (nlohmann::json obj) ;
    template <>
    ApollocommonmonitorMonitorMessageItem from_json<ApollocommonmonitorMonitorMessageItem>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonmonitorMonitorMessageItem &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonmonitorMonitorMessageItem & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonmonitorMonitorMessageItem & dt);
}
