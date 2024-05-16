#pragma once
#include "apollo_msgs/msg/apollocanbus_scu1301.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScu1301 &msg) ;
    ApollocanbusScu1301 from_json_ApollocanbusScu1301 (nlohmann::json obj) ;
    template <>
    ApollocanbusScu1301 from_json<ApollocanbusScu1301>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScu1301 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScu1301 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScu1301 & dt);
}
