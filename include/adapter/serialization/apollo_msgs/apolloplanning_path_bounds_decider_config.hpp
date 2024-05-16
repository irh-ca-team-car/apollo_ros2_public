#pragma once
#include "apollo_msgs/msg/apolloplanning_path_bounds_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathBoundsDeciderConfig &msg) ;
    ApolloplanningPathBoundsDeciderConfig from_json_ApolloplanningPathBoundsDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPathBoundsDeciderConfig from_json<ApolloplanningPathBoundsDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathBoundsDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathBoundsDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathBoundsDeciderConfig & dt);
}
