#pragma once
#include "apollo_msgs/msg/apollorelative_map_navigation_path.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapNavigationPath &msg) ;
    ApollorelativeMapNavigationPath from_json_ApollorelativeMapNavigationPath (nlohmann::json obj) ;
    template <>
    ApollorelativeMapNavigationPath from_json<ApollorelativeMapNavigationPath>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapNavigationPath &dt);
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapNavigationPath & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapNavigationPath & dt);
}
