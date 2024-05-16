#pragma once
#include "apollo_msgs/msg/apollocanbus_fail241.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFail241 &msg) ;
    ApollocanbusFail241 from_json_ApollocanbusFail241 (nlohmann::json obj) ;
    template <>
    ApollocanbusFail241 from_json<ApollocanbusFail241>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFail241 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFail241 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFail241 & dt);
}
