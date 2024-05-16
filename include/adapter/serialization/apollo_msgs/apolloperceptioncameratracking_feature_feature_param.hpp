#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_feature_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_extractor_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeatureFeatureParam &msg) ;
    ApolloperceptioncameratrackingFeatureFeatureParam from_json_ApolloperceptioncameratrackingFeatureFeatureParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameratrackingFeatureFeatureParam from_json<ApolloperceptioncameratrackingFeatureFeatureParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeatureFeatureParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeatureFeatureParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeatureFeatureParam & dt);
}
