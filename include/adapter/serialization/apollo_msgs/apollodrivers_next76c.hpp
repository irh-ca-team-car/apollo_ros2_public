#pragma once
#include "apollo_msgs/msg/apollodrivers_next76c.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversNext76c &msg) ;
    ApollodriversNext76c from_json_ApollodriversNext76c (nlohmann::json obj) ;
    template <>
    ApollodriversNext76c from_json<ApollodriversNext76c>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversNext76c &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversNext76c & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversNext76c & dt);
}
