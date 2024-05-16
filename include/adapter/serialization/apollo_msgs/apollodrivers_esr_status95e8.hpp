#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_status95e8.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus95e8 &msg) ;
    ApollodriversEsrStatus95e8 from_json_ApollodriversEsrStatus95e8 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrStatus95e8 from_json<ApollodriversEsrStatus95e8>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus95e8 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus95e8 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus95e8 & dt);
}
