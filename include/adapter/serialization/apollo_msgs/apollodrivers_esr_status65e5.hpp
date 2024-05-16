#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_status65e5.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus65e5 &msg) ;
    ApollodriversEsrStatus65e5 from_json_ApollodriversEsrStatus65e5 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrStatus65e5 from_json<ApollodriversEsrStatus65e5>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus65e5 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus65e5 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus65e5 & dt);
}
