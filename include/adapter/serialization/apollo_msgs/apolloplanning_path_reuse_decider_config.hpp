#pragma once
#include "apollo_msgs/msg/apolloplanning_path_reuse_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathReuseDeciderConfig &msg) ;
    ApolloplanningPathReuseDeciderConfig from_json_ApolloplanningPathReuseDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPathReuseDeciderConfig from_json<ApolloplanningPathReuseDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathReuseDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathReuseDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathReuseDeciderConfig & dt);
}
