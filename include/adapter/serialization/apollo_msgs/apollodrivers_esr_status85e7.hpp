#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_status85e7.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus85e7 &msg) ;
    ApollodriversEsrStatus85e7 from_json_ApollodriversEsrStatus85e7 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrStatus85e7 from_json<ApollodriversEsrStatus85e7>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus85e7 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus85e7 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus85e7 & dt);
}
