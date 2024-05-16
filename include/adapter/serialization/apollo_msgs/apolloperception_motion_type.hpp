#pragma once
#include "apollo_msgs/msg/apolloperception_motion_type.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionMotionType &msg) ;
    ApolloperceptionMotionType from_json_ApolloperceptionMotionType (nlohmann::json obj) ;
    template <>
    ApolloperceptionMotionType from_json<ApolloperceptionMotionType>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionMotionType &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionMotionType & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionMotionType & dt);
}
