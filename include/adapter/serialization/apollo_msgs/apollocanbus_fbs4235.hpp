#pragma once
#include "apollo_msgs/msg/apollocanbus_fbs4235.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFbs4235 &msg) ;
    ApollocanbusFbs4235 from_json_ApollocanbusFbs4235 (nlohmann::json obj) ;
    template <>
    ApollocanbusFbs4235 from_json<ApollocanbusFbs4235>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFbs4235 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFbs4235 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFbs4235 & dt);
}
