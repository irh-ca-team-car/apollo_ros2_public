#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_roi_boundary_filter_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarROIBoundaryFilterConfig &msg) ;
    ApolloperceptionlidarROIBoundaryFilterConfig from_json_ApolloperceptionlidarROIBoundaryFilterConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarROIBoundaryFilterConfig from_json<ApolloperceptionlidarROIBoundaryFilterConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarROIBoundaryFilterConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarROIBoundaryFilterConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarROIBoundaryFilterConfig & dt);
}
