#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_roi_pooling_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeatureROIPoolingParam &msg) ;
    ApolloperceptioncameratrackingFeatureROIPoolingParam from_json_ApolloperceptioncameratrackingFeatureROIPoolingParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameratrackingFeatureROIPoolingParam from_json<ApolloperceptioncameratrackingFeatureROIPoolingParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeatureROIPoolingParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeatureROIPoolingParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeatureROIPoolingParam & dt);
}
