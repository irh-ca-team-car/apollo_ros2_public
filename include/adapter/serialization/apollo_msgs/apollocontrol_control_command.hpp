#pragma once
#include "apollo_msgs/msg/apollocontrol_control_command.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_signal.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_latency_stats.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_pad_message.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_engage_advice.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolControlCommand &msg) ;
    ApollocontrolControlCommand from_json_ApollocontrolControlCommand (nlohmann::json obj) ;
    template <>
    ApollocontrolControlCommand from_json<ApollocontrolControlCommand>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolControlCommand &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolControlCommand & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolControlCommand & dt);
}
