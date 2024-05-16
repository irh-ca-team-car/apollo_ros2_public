#pragma once
#include "apollo_msgs/msg/apollocanbus_scu3303.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScu3303 &msg) ;
    ApollocanbusScu3303 from_json_ApollocanbusScu3303 (nlohmann::json obj) ;
    template <>
    ApollocanbusScu3303 from_json<ApollocanbusScu3303>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScu3303 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScu3303 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScu3303 & dt);
}
