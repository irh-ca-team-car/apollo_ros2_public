#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraomt_kalman_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtKalmanParam &msg) ;
    ApolloperceptioncameraomtKalmanParam from_json_ApolloperceptioncameraomtKalmanParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraomtKalmanParam from_json<ApolloperceptioncameraomtKalmanParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtKalmanParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtKalmanParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtKalmanParam & dt);
}
