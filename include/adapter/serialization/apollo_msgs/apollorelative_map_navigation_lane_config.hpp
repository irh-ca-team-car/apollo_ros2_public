#pragma once
#include "apollo_msgs/msg/apollorelative_map_navigation_lane_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapNavigationLaneConfig &msg) ;
    ApollorelativeMapNavigationLaneConfig from_json_ApollorelativeMapNavigationLaneConfig (nlohmann::json obj) ;
    template <>
    ApollorelativeMapNavigationLaneConfig from_json<ApollorelativeMapNavigationLaneConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapNavigationLaneConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapNavigationLaneConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapNavigationLaneConfig & dt);
}
