#pragma once
#include "apollo_msgs/msg/apolloplanning_path_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathDeciderConfig &msg) ;
    ApolloplanningPathDeciderConfig from_json_ApolloplanningPathDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPathDeciderConfig from_json<ApolloplanningPathDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathDeciderConfig & dt);
}
