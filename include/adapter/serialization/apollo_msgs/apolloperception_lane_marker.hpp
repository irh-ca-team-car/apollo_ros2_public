#pragma once
#include "apollo_msgs/msg/apolloperception_lane_marker.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionLaneMarker &msg) ;
    ApolloperceptionLaneMarker from_json_ApolloperceptionLaneMarker (nlohmann::json obj) ;
    template <>
    ApolloperceptionLaneMarker from_json<ApolloperceptionLaneMarker>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionLaneMarker &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionLaneMarker & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionLaneMarker & dt);
}
