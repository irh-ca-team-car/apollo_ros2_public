#pragma once
#include "apollo_msgs/msg/apollov2x_intersection_traffic_light_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_road_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xIntersectionTrafficLightData &msg) ;
    Apollov2xIntersectionTrafficLightData from_json_Apollov2xIntersectionTrafficLightData (nlohmann::json obj) ;
    template <>
    Apollov2xIntersectionTrafficLightData from_json<Apollov2xIntersectionTrafficLightData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xIntersectionTrafficLightData &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xIntersectionTrafficLightData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xIntersectionTrafficLightData & dt);
}
