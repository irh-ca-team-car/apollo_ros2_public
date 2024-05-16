#pragma once
#include "apollo_msgs/msg/apolloperceptioncameralocation_refiner_location_refiner_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameralocationRefinerLocationRefinerParam &msg) ;
    ApolloperceptioncameralocationRefinerLocationRefinerParam from_json_ApolloperceptioncameralocationRefinerLocationRefinerParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameralocationRefinerLocationRefinerParam from_json<ApolloperceptioncameralocationRefinerLocationRefinerParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameralocationRefinerLocationRefinerParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameralocationRefinerLocationRefinerParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameralocationRefinerLocationRefinerParam & dt);
}
