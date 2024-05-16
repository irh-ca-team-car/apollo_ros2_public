#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_status34e2.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus34e2 &msg) ;
    ApollodriversEsrStatus34e2 from_json_ApollodriversEsrStatus34e2 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrStatus34e2 from_json<ApollodriversEsrStatus34e2>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus34e2 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus34e2 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus34e2 & dt);
}
