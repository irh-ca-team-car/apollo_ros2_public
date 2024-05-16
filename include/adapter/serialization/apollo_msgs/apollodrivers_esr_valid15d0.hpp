#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_valid15d0.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrValid15d0 &msg) ;
    ApollodriversEsrValid15d0 from_json_ApollodriversEsrValid15d0 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrValid15d0 from_json<ApollodriversEsrValid15d0>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrValid15d0 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrValid15d0 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrValid15d0 & dt);
}
