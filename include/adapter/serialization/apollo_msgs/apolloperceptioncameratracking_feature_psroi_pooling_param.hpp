#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_psroi_pooling_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeaturePSROIPoolingParam &msg) ;
    ApolloperceptioncameratrackingFeaturePSROIPoolingParam from_json_ApolloperceptioncameratrackingFeaturePSROIPoolingParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameratrackingFeaturePSROIPoolingParam from_json<ApolloperceptioncameratrackingFeaturePSROIPoolingParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeaturePSROIPoolingParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeaturePSROIPoolingParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeaturePSROIPoolingParam & dt);
}
