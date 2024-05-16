#pragma once
#include "apollo_msgs/msg/apollodrivers_radar_state201.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRadarState201 &msg) ;
    ApollodriversRadarState201 from_json_ApollodriversRadarState201 (nlohmann::json obj) ;
    template <>
    ApollodriversRadarState201 from_json<ApollodriversRadarState201>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRadarState201 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversRadarState201 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRadarState201 & dt);
}
