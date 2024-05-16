#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_mlf_tracker_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfTrackerConfig &msg) ;
    ApolloperceptionlidarMlfTrackerConfig from_json_ApolloperceptionlidarMlfTrackerConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarMlfTrackerConfig from_json<ApolloperceptionlidarMlfTrackerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfTrackerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfTrackerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfTrackerConfig & dt);
}
