#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_end_points.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraEndPoints &msg) ;
    ApolloperceptioncameraEndPoints from_json_ApolloperceptioncameraEndPoints (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraEndPoints from_json<ApolloperceptioncameraEndPoints>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraEndPoints &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraEndPoints & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraEndPoints & dt);
}
