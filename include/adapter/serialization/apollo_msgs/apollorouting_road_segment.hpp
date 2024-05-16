#pragma once
#include "apollo_msgs/msg/apollorouting_road_segment.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_passage.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingRoadSegment &msg) ;
    ApolloroutingRoadSegment from_json_ApolloroutingRoadSegment (nlohmann::json obj) ;
    template <>
    ApolloroutingRoadSegment from_json<ApolloroutingRoadSegment>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingRoadSegment &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingRoadSegment & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingRoadSegment & dt);
}
