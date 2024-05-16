#pragma once
#include "apollo_msgs/msg/apollorouting_lane_segment.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingLaneSegment &msg) ;
    ApolloroutingLaneSegment from_json_ApolloroutingLaneSegment (nlohmann::json obj) ;
    template <>
    ApolloroutingLaneSegment from_json<ApolloroutingLaneSegment>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingLaneSegment &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingLaneSegment & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingLaneSegment & dt);
}
