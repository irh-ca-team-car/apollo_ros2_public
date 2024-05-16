#pragma once
#include "apollo_msgs/msg/apolloplanning_st_bounds_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSTBoundsDeciderConfig &msg) ;
    ApolloplanningSTBoundsDeciderConfig from_json_ApolloplanningSTBoundsDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningSTBoundsDeciderConfig from_json<ApolloplanningSTBoundsDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSTBoundsDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSTBoundsDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSTBoundsDeciderConfig & dt);
}
