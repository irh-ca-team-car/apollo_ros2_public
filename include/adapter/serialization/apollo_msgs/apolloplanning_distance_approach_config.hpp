#pragma once
#include "apollo_msgs/msg/apolloplanning_distance_approach_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_ipopt_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDistanceApproachConfig &msg) ;
    ApolloplanningDistanceApproachConfig from_json_ApolloplanningDistanceApproachConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningDistanceApproachConfig from_json<ApolloplanningDistanceApproachConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDistanceApproachConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDistanceApproachConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDistanceApproachConfig & dt);
}
