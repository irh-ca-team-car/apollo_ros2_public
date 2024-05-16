#pragma once
#include "apollo_msgs/msg/apollocanbus_hazard_lights_cmd114.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHazardLightsCmd114 &msg) ;
    ApollocanbusHazardLightsCmd114 from_json_ApollocanbusHazardLightsCmd114 (nlohmann::json obj) ;
    template <>
    ApollocanbusHazardLightsCmd114 from_json<ApollocanbusHazardLightsCmd114>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHazardLightsCmd114 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHazardLightsCmd114 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHazardLightsCmd114 & dt);
}
