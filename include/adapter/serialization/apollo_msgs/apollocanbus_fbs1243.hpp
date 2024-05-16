#pragma once
#include "apollo_msgs/msg/apollocanbus_fbs1243.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFbs1243 &msg) ;
    ApollocanbusFbs1243 from_json_ApollocanbusFbs1243 (nlohmann::json obj) ;
    template <>
    ApollocanbusFbs1243 from_json<ApollocanbusFbs1243>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFbs1243 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFbs1243 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFbs1243 & dt);
}
