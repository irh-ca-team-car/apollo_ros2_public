#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_spatio_temporal_ground_detector_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarSpatioTemporalGroundDetectorConfig &msg) ;
    ApolloperceptionlidarSpatioTemporalGroundDetectorConfig from_json_ApolloperceptionlidarSpatioTemporalGroundDetectorConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarSpatioTemporalGroundDetectorConfig from_json<ApolloperceptionlidarSpatioTemporalGroundDetectorConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarSpatioTemporalGroundDetectorConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarSpatioTemporalGroundDetectorConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarSpatioTemporalGroundDetectorConfig & dt);
}
