#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_mlf_motion_refiner_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfMotionRefinerConfig &msg) ;
    ApolloperceptionlidarMlfMotionRefinerConfig from_json_ApolloperceptionlidarMlfMotionRefinerConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarMlfMotionRefinerConfig from_json<ApolloperceptionlidarMlfMotionRefinerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfMotionRefinerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfMotionRefinerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfMotionRefinerConfig & dt);
}
