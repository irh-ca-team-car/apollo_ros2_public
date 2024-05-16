#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraomt_omt_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_weight_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_target_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_reference_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtOmtParam &msg) ;
    ApolloperceptioncameraomtOmtParam from_json_ApolloperceptioncameraomtOmtParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraomtOmtParam from_json<ApolloperceptioncameraomtOmtParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtOmtParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtOmtParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtOmtParam & dt);
}
