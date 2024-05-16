#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_hd_map_roi_filter_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarHDMapRoiFilterConfig &msg) ;
    ApolloperceptionlidarHDMapRoiFilterConfig from_json_ApolloperceptionlidarHDMapRoiFilterConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarHDMapRoiFilterConfig from_json<ApolloperceptionlidarHDMapRoiFilterConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarHDMapRoiFilterConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarHDMapRoiFilterConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarHDMapRoiFilterConfig & dt);
}
