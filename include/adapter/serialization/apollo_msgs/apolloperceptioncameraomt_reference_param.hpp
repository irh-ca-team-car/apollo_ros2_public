#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraomt_reference_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtReferenceParam &msg) ;
    ApolloperceptioncameraomtReferenceParam from_json_ApolloperceptioncameraomtReferenceParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraomtReferenceParam from_json<ApolloperceptioncameraomtReferenceParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtReferenceParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtReferenceParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtReferenceParam & dt);
}
