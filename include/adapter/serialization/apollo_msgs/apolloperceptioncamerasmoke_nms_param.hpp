#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_nms_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeNMSParam &msg) ;
    ApolloperceptioncamerasmokeNMSParam from_json_ApolloperceptioncamerasmokeNMSParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerasmokeNMSParam from_json<ApolloperceptioncamerasmokeNMSParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeNMSParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeNMSParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeNMSParam & dt);
}
