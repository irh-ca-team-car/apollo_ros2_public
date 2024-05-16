#pragma once
#include "apollo_msgs/msg/apollohdmap_rsu.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRSU &msg) ;
    ApollohdmapRSU from_json_ApollohdmapRSU (nlohmann::json obj) ;
    template <>
    ApollohdmapRSU from_json<ApollohdmapRSU>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRSU &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRSU & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRSU & dt);
}
