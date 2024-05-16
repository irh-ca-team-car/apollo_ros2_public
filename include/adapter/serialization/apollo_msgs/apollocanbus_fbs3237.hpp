#pragma once
#include "apollo_msgs/msg/apollocanbus_fbs3237.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFbs3237 &msg) ;
    ApollocanbusFbs3237 from_json_ApollocanbusFbs3237 (nlohmann::json obj) ;
    template <>
    ApollocanbusFbs3237 from_json<ApollocanbusFbs3237>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFbs3237 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFbs3237 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFbs3237 & dt);
}
