#pragma once
#include "apollo_msgs/msg/apollocanbus_scu2302.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScu2302 &msg) ;
    ApollocanbusScu2302 from_json_ApollocanbusScu2302 (nlohmann::json obj) ;
    template <>
    ApollocanbusScu2302 from_json<ApollocanbusScu2302>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScu2302 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScu2302 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScu2302 & dt);
}
