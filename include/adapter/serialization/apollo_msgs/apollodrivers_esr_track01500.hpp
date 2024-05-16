#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_track01500.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrTrack01500 &msg) ;
    ApollodriversEsrTrack01500 from_json_ApollodriversEsrTrack01500 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrTrack01500 from_json<ApollodriversEsrTrack01500>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrTrack01500 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrTrack01500 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrTrack01500 & dt);
}
