#pragma once
#include "apollo_msgs/msg/apolloperception_light_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionLightStatus &msg) ;
    ApolloperceptionLightStatus from_json_ApolloperceptionLightStatus (nlohmann::json obj) ;
    template <>
    ApolloperceptionLightStatus from_json<ApolloperceptionLightStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionLightStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionLightStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionLightStatus & dt);
}
