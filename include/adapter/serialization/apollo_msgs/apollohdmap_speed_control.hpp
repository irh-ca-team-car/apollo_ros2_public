#pragma once
#include "apollo_msgs/msg/apollohdmap_speed_control.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSpeedControl &msg) ;
    ApollohdmapSpeedControl from_json_ApollohdmapSpeedControl (nlohmann::json obj) ;
    template <>
    ApollohdmapSpeedControl from_json<ApollohdmapSpeedControl>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSpeedControl &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSpeedControl & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSpeedControl & dt);
}
