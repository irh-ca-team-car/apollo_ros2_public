#pragma once
#include "apollo_msgs/msg/apollohdmap_speed_bump.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSpeedBump &msg) ;
    ApollohdmapSpeedBump from_json_ApollohdmapSpeedBump (nlohmann::json obj) ;
    template <>
    ApollohdmapSpeedBump from_json<ApollohdmapSpeedBump>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSpeedBump &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSpeedBump & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSpeedBump & dt);
}
