#pragma once
#include "apollo_msgs/msg/apollodrivers_details737.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDetails737 &msg) ;
    ApollodriversDetails737 from_json_ApollodriversDetails737 (nlohmann::json obj) ;
    template <>
    ApollodriversDetails737 from_json<ApollodriversDetails737>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDetails737 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversDetails737 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDetails737 & dt);
}
