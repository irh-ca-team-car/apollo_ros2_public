#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_status24e1.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus24e1 &msg) ;
    ApollodriversEsrStatus24e1 from_json_ApollodriversEsrStatus24e1 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrStatus24e1 from_json<ApollodriversEsrStatus24e1>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus24e1 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus24e1 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus24e1 & dt);
}
