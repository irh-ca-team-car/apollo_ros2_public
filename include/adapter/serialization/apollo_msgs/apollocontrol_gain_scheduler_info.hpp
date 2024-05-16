#pragma once
#include "apollo_msgs/msg/apollocontrol_gain_scheduler_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolGainSchedulerInfo &msg) ;
    ApollocontrolGainSchedulerInfo from_json_ApollocontrolGainSchedulerInfo (nlohmann::json obj) ;
    template <>
    ApollocontrolGainSchedulerInfo from_json<ApollocontrolGainSchedulerInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolGainSchedulerInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolGainSchedulerInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolGainSchedulerInfo & dt);
}
