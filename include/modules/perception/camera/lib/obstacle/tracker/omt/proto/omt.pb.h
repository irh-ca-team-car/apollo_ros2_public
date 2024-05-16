#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraomt_kalman_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_kalman_param.hpp"
namespace apollo::perception::camera::omt{
	typedef apollo_msgs::msg::ApolloperceptioncameraomtKalmanParam KalmanParam;
}
#include "apollo_msgs/msg/apolloperceptioncameraomt_target_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_target_param.hpp"
namespace apollo::perception::camera::omt{
	typedef apollo_msgs::msg::ApolloperceptioncameraomtTargetParam TargetParam;
}
#include "apollo_msgs/msg/apolloperceptioncameraomt_reference_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_reference_param.hpp"
namespace apollo::perception::camera::omt{
	typedef apollo_msgs::msg::ApolloperceptioncameraomtReferenceParam ReferenceParam;
}
#include "apollo_msgs/msg/apolloperceptioncameraomt_weight_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_weight_param.hpp"
namespace apollo::perception::camera::omt{
	typedef apollo_msgs::msg::ApolloperceptioncameraomtWeightParam WeightParam;
}
#include "apollo_msgs/msg/apolloperceptioncameraomt_omt_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_omt_param.hpp"
namespace apollo::perception::camera::omt{
	typedef apollo_msgs::msg::ApolloperceptioncameraomtOmtParam OmtParam;
}