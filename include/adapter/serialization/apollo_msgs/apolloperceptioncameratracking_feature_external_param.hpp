#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_external_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeatureExternalParam &msg) ;
    ApolloperceptioncameratrackingFeatureExternalParam from_json_ApolloperceptioncameratrackingFeatureExternalParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameratrackingFeatureExternalParam from_json<ApolloperceptioncameratrackingFeatureExternalParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeatureExternalParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeatureExternalParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeatureExternalParam & dt);
}
