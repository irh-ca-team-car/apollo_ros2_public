#pragma once
#include "apollo_msgs/msg/apollohdmap_speed_controls.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_speed_control.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSpeedControls &msg) ;
    ApollohdmapSpeedControls from_json_ApollohdmapSpeedControls (nlohmann::json obj) ;
    template <>
    ApollohdmapSpeedControls from_json<ApollohdmapSpeedControls>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSpeedControls &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSpeedControls & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSpeedControls & dt);
}
