#pragma once
#include "apollo_msgs/msg/apolloperception_motion_service.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_vehicle_status.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionMotionService &msg) ;
    ApolloperceptionMotionService from_json_ApolloperceptionMotionService (nlohmann::json obj) ;
    template <>
    ApolloperceptionMotionService from_json<ApolloperceptionMotionService>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionMotionService &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionMotionService & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionMotionService & dt);
}
