#pragma once
#include "apollo_msgs/msg/apollorelative_map_navigation_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_navigation_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapNavigationInfo &msg) ;
    ApollorelativeMapNavigationInfo from_json_ApollorelativeMapNavigationInfo (nlohmann::json obj) ;
    template <>
    ApollorelativeMapNavigationInfo from_json<ApollorelativeMapNavigationInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapNavigationInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapNavigationInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapNavigationInfo & dt);
}
