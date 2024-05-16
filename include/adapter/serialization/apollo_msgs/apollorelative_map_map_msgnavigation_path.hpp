#pragma once
#include "apollo_msgs/msg/apollorelative_map_map_msgnavigation_path.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorelative_map_navigation_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapMapMsgnavigationPath &msg) ;
    ApollorelativeMapMapMsgnavigationPath from_json_ApollorelativeMapMapMsgnavigationPath (nlohmann::json obj) ;
    template <>
    ApollorelativeMapMapMsgnavigationPath from_json<ApollorelativeMapMapMsgnavigationPath>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapMapMsgnavigationPath &dt);
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapMapMsgnavigationPath & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapMapMsgnavigationPath & dt);
}
