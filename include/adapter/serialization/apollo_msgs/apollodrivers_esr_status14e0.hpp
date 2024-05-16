#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_status14e0.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus14e0 &msg) ;
    ApollodriversEsrStatus14e0 from_json_ApollodriversEsrStatus14e0 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrStatus14e0 from_json<ApollodriversEsrStatus14e0>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus14e0 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus14e0 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus14e0 & dt);
}
