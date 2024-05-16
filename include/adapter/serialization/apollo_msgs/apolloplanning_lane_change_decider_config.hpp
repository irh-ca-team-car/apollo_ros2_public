#pragma once
#include "apollo_msgs/msg/apolloplanning_lane_change_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLaneChangeDeciderConfig &msg) ;
    ApolloplanningLaneChangeDeciderConfig from_json_ApolloplanningLaneChangeDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningLaneChangeDeciderConfig from_json<ApolloplanningLaneChangeDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLaneChangeDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLaneChangeDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLaneChangeDeciderConfig & dt);
}
