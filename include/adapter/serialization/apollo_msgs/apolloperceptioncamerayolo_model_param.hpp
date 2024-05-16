#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerayolo_model_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_dimension_statistics.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_b_box_statistics.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerayoloModelParam &msg) ;
    ApolloperceptioncamerayoloModelParam from_json_ApolloperceptioncamerayoloModelParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerayoloModelParam from_json<ApolloperceptioncamerayoloModelParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerayoloModelParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerayoloModelParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerayoloModelParam & dt);
}
