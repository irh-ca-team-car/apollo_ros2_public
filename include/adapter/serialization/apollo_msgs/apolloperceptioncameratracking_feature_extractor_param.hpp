#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_extractor_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_roi_pooling_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_psroi_pooling_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeatureExtractorParam &msg) ;
    ApolloperceptioncameratrackingFeatureExtractorParam from_json_ApolloperceptioncameratrackingFeatureExtractorParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameratrackingFeatureExtractorParam from_json<ApolloperceptioncameratrackingFeatureExtractorParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeatureExtractorParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeatureExtractorParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeatureExtractorParam & dt);
}
