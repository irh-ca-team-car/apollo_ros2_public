#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_status55e4.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus55e4 &msg) ;
    ApollodriversEsrStatus55e4 from_json_ApollodriversEsrStatus55e4 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrStatus55e4 from_json<ApollodriversEsrStatus55e4>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus55e4 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus55e4 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus55e4 & dt);
}
