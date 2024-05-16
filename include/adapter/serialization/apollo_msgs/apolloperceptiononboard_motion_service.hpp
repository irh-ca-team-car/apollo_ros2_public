#pragma once
#include "apollo_msgs/msg/apolloperceptiononboard_motion_service.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardMotionService &msg) ;
    ApolloperceptiononboardMotionService from_json_ApolloperceptiononboardMotionService (nlohmann::json obj) ;
    template <>
    ApolloperceptiononboardMotionService from_json<ApolloperceptiononboardMotionService>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardMotionService &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardMotionService & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardMotionService & dt);
}
