#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_mlf_track_object_matcher_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfTrackObjectMatcherConfig &msg) ;
    ApolloperceptionlidarMlfTrackObjectMatcherConfig from_json_ApolloperceptionlidarMlfTrackObjectMatcherConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarMlfTrackObjectMatcherConfig from_json<ApolloperceptionlidarMlfTrackObjectMatcherConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfTrackObjectMatcherConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfTrackObjectMatcherConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfTrackObjectMatcherConfig & dt);
}
