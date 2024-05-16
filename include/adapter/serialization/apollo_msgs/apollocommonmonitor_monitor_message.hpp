#pragma once
#include "apollo_msgs/msg/apollocommonmonitor_monitor_message.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommonmonitor_monitor_message_item.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonmonitorMonitorMessage &msg) ;
    ApollocommonmonitorMonitorMessage from_json_ApollocommonmonitorMonitorMessage (nlohmann::json obj) ;
    template <>
    ApollocommonmonitorMonitorMessage from_json<ApollocommonmonitorMonitorMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonmonitorMonitorMessage &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonmonitorMonitorMessage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonmonitorMonitorMessage & dt);
}
