#pragma once
#include "apollo_msgs/msg/apollorelative_map_navigator_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorelative_map_sample_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapNavigatorConfig &msg) ;
    ApollorelativeMapNavigatorConfig from_json_ApollorelativeMapNavigatorConfig (nlohmann::json obj) ;
    template <>
    ApollorelativeMapNavigatorConfig from_json<ApollorelativeMapNavigatorConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapNavigatorConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapNavigatorConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapNavigatorConfig & dt);
}
