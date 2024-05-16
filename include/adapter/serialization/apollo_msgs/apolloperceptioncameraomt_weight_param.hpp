#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraomt_weight_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtWeightParam &msg) ;
    ApolloperceptioncameraomtWeightParam from_json_ApolloperceptioncameraomtWeightParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraomtWeightParam from_json<ApolloperceptioncameraomtWeightParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtWeightParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtWeightParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtWeightParam & dt);
}
