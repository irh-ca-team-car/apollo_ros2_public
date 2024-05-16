#pragma once
#include "apollo_msgs/msg/apolloplanning_rss_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRSSInfo &msg) ;
    ApolloplanningRSSInfo from_json_ApolloplanningRSSInfo (nlohmann::json obj) ;
    template <>
    ApolloplanningRSSInfo from_json<ApolloplanningRSSInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRSSInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRSSInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRSSInfo & dt);
}
