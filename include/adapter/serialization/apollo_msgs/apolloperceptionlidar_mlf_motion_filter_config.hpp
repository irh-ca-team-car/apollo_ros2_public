#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_mlf_motion_filter_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfMotionFilterConfig &msg) ;
    ApolloperceptionlidarMlfMotionFilterConfig from_json_ApolloperceptionlidarMlfMotionFilterConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarMlfMotionFilterConfig from_json<ApolloperceptionlidarMlfMotionFilterConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfMotionFilterConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfMotionFilterConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfMotionFilterConfig & dt);
}
