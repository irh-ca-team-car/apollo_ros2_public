#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerayolo_yolo_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_model_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_network_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_nms_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerayoloYoloParam &msg) ;
    ApolloperceptioncamerayoloYoloParam from_json_ApolloperceptioncamerayoloYoloParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerayoloYoloParam from_json<ApolloperceptioncamerayoloYoloParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerayoloYoloParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerayoloYoloParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerayoloYoloParam & dt);
}
