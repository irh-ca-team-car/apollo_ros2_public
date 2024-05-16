#pragma once
#include "apollo_msgs/msg/apolloperception_camera_valid_dist.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_camera_valid_dist.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionCameraValidDist CameraValidDist;
}
#include "apollo_msgs/msg/apolloperception_dst_existence_fusion_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_dst_existence_fusion_config.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionDstExistenceFusionConfig DstExistenceFusionConfig;
}