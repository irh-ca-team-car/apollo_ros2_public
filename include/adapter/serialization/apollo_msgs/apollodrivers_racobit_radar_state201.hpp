#pragma once
#include "apollo_msgs/msg/apollodrivers_racobit_radar_state201.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRacobitRadarState201 &msg) ;
    ApollodriversRacobitRadarState201 from_json_ApollodriversRacobitRadarState201 (nlohmann::json obj) ;
    template <>
    ApollodriversRacobitRadarState201 from_json<ApollodriversRacobitRadarState201>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRacobitRadarState201 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversRacobitRadarState201 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRacobitRadarState201 & dt);
}
