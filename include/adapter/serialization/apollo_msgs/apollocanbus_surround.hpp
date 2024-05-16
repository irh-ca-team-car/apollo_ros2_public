#pragma once
#include "apollo_msgs/msg/apollocanbus_surround.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_sonar.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSurround &msg) ;
    ApollocanbusSurround from_json_ApollocanbusSurround (nlohmann::json obj) ;
    template <>
    ApollocanbusSurround from_json<ApollocanbusSurround>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSurround &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSurround & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSurround & dt);
}
