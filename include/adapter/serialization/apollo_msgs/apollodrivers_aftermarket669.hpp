#pragma once
#include "apollo_msgs/msg/apollodrivers_aftermarket669.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversAftermarket669 &msg) ;
    ApollodriversAftermarket669 from_json_ApollodriversAftermarket669 (nlohmann::json obj) ;
    template <>
    ApollodriversAftermarket669 from_json<ApollodriversAftermarket669>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversAftermarket669 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversAftermarket669 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversAftermarket669 & dt);
}
