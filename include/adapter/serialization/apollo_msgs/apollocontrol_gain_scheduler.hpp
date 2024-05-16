#pragma once
#include "apollo_msgs/msg/apollocontrol_gain_scheduler.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontrol_gain_scheduler_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolGainScheduler &msg) ;
    ApollocontrolGainScheduler from_json_ApollocontrolGainScheduler (nlohmann::json obj) ;
    template <>
    ApollocontrolGainScheduler from_json<ApollocontrolGainScheduler>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolGainScheduler &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolGainScheduler & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolGainScheduler & dt);
}
