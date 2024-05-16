#pragma once
#include "apollo_msgs/msg/apolloplanning_open_space_pre_stop_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpacePreStopDeciderConfig &msg) ;
    ApolloplanningOpenSpacePreStopDeciderConfig from_json_ApolloplanningOpenSpacePreStopDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningOpenSpacePreStopDeciderConfig from_json<ApolloplanningOpenSpacePreStopDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpacePreStopDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpacePreStopDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpacePreStopDeciderConfig & dt);
}
