#pragma once
#include "apollo_msgs/msg/apolloperception_perception_lanes.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_calibrator.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_lane_line.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionPerceptionLanes &msg) ;
    ApolloperceptionPerceptionLanes from_json_ApolloperceptionPerceptionLanes (nlohmann::json obj) ;
    template <>
    ApolloperceptionPerceptionLanes from_json<ApolloperceptionPerceptionLanes>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionPerceptionLanes &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionPerceptionLanes & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionPerceptionLanes & dt);
}
