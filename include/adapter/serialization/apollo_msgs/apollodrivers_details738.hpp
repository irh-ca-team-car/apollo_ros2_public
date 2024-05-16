#pragma once
#include "apollo_msgs/msg/apollodrivers_details738.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDetails738 &msg) ;
    ApollodriversDetails738 from_json_ApollodriversDetails738 (nlohmann::json obj) ;
    template <>
    ApollodriversDetails738 from_json<ApollodriversDetails738>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDetails738 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversDetails738 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDetails738 & dt);
}
