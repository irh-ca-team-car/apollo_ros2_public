#pragma once
#include "apollo_msgs/msg/apolloperception_lane_markers.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_lane_marker.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionLaneMarkers &msg) ;
    ApolloperceptionLaneMarkers from_json_ApolloperceptionLaneMarkers (nlohmann::json obj) ;
    template <>
    ApolloperceptionLaneMarkers from_json<ApolloperceptionLaneMarkers>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionLaneMarkers &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionLaneMarkers & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionLaneMarkers & dt);
}
