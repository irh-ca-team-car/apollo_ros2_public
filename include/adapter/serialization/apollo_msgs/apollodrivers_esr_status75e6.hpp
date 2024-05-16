#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_status75e6.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus75e6 &msg) ;
    ApollodriversEsrStatus75e6 from_json_ApollodriversEsrStatus75e6 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrStatus75e6 from_json<ApollodriversEsrStatus75e6>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus75e6 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus75e6 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus75e6 & dt);
}
