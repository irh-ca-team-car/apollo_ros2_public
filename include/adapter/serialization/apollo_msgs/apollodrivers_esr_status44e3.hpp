#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_status44e3.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus44e3 &msg) ;
    ApollodriversEsrStatus44e3 from_json_ApollodriversEsrStatus44e3 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrStatus44e3 from_json<ApollodriversEsrStatus44e3>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus44e3 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus44e3 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus44e3 & dt);
}
