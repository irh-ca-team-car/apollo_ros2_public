#pragma once
#include "apollo_msgs/msg/apollodrivers_lka769.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLka769 &msg) ;
    ApollodriversLka769 from_json_ApollodriversLka769 (nlohmann::json obj) ;
    template <>
    ApollodriversLka769 from_json<ApollodriversLka769>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLka769 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversLka769 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLka769 & dt);
}
