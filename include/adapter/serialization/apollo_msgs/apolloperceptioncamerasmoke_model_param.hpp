#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_model_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_dimension_statistics.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_b_box_statistics.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeModelParam &msg) ;
    ApolloperceptioncamerasmokeModelParam from_json_ApolloperceptioncamerasmokeModelParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerasmokeModelParam from_json<ApolloperceptioncamerasmokeModelParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeModelParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeModelParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeModelParam & dt);
}
