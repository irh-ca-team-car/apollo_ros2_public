#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_valid25d1.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrValid25d1 &msg) ;
    ApollodriversEsrValid25d1 from_json_ApollodriversEsrValid25d1 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrValid25d1 from_json<ApollodriversEsrValid25d1>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrValid25d1 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrValid25d1 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrValid25d1 & dt);
}
