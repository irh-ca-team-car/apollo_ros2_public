#pragma once
#include "apollo_msgs/msg/apollorelative_map_relative_map_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorelative_map_map_generation_param.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_navigation_lane_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapRelativeMapConfig &msg) ;
    ApollorelativeMapRelativeMapConfig from_json_ApollorelativeMapRelativeMapConfig (nlohmann::json obj) ;
    template <>
    ApollorelativeMapRelativeMapConfig from_json<ApollorelativeMapRelativeMapConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapRelativeMapConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapRelativeMapConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapRelativeMapConfig & dt);
}
