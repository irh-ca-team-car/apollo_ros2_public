#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraomt_target_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_kalman_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtTargetParam &msg) ;
    ApolloperceptioncameraomtTargetParam from_json_ApolloperceptioncameraomtTargetParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraomtTargetParam from_json<ApolloperceptioncameraomtTargetParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtTargetParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtTargetParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtTargetParam & dt);
}
