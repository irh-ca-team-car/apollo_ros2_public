#pragma once
#include "apollo_msgs/msg/apolloplanning_open_space_fall_back_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceFallBackDeciderConfig &msg) ;
    ApolloplanningOpenSpaceFallBackDeciderConfig from_json_ApolloplanningOpenSpaceFallBackDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningOpenSpaceFallBackDeciderConfig from_json<ApolloplanningOpenSpaceFallBackDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceFallBackDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceFallBackDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceFallBackDeciderConfig & dt);
}
