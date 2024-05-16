#pragma once
#include "apollo_msgs/msg/apollorouting_landmark.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_lane_waypoint.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_parking_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingLandmark &msg) ;
    ApolloroutingLandmark from_json_ApolloroutingLandmark (nlohmann::json obj) ;
    template <>
    ApolloroutingLandmark from_json<ApolloroutingLandmark>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingLandmark &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingLandmark & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingLandmark & dt);
}
