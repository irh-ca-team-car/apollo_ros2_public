#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_feature_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_feature_param.hpp"
namespace apollo::perception::camera::tracking_feature{
	typedef apollo_msgs::msg::ApolloperceptioncameratrackingFeatureFeatureParam FeatureParam;
}
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_extractor_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_extractor_param.hpp"
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_roi_pooling_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_roi_pooling_param.hpp"
namespace apollo::perception::camera::tracking_feature{
	typedef apollo_msgs::msg::ApolloperceptioncameratrackingFeatureROIPoolingParam ROIPoolingParam;
}
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_psroi_pooling_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_psroi_pooling_param.hpp"
namespace apollo::perception::camera::tracking_feature{
	typedef apollo_msgs::msg::ApolloperceptioncameratrackingFeaturePSROIPoolingParam PSROIPoolingParam;
}
#include "apollo_msgs/msg/apolloperceptioncameratracking_feature_external_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_external_param.hpp"
namespace apollo::perception::camera::tracking_feature{
	typedef apollo_msgs::msg::ApolloperceptioncameratrackingFeatureExternalParam ExternalParam;
}
namespace apollo::perception::camera::tracking_feature::ExtractorParam{
	enum FeatureType {
		ROIPooling = 0
	};
}