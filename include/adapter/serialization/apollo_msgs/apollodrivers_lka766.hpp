#pragma once
#include "apollo_msgs/msg/apollodrivers_lka766.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLka766 &msg) ;
    ApollodriversLka766 from_json_ApollodriversLka766 (nlohmann::json obj) ;
    template <>
    ApollodriversLka766 from_json<ApollodriversLka766>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLka766 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversLka766 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLka766 & dt);
}
