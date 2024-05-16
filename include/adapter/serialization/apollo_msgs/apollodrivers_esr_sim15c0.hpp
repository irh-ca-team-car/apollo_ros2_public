#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_sim15c0.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrSim15c0 &msg) ;
    ApollodriversEsrSim15c0 from_json_ApollodriversEsrSim15c0 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrSim15c0 from_json<ApollodriversEsrSim15c0>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrSim15c0 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrSim15c0 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrSim15c0 & dt);
}
