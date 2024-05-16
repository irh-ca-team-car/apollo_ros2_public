#pragma once
#include "apollo_msgs/msg/apollocanbus_fbs2240.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFbs2240 &msg) ;
    ApollocanbusFbs2240 from_json_ApollocanbusFbs2240 (nlohmann::json obj) ;
    template <>
    ApollocanbusFbs2240 from_json<ApollocanbusFbs2240>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFbs2240 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFbs2240 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFbs2240 & dt);
}
