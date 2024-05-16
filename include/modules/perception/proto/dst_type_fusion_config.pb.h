#pragma once
#include "apollo_msgs/msg/apolloperceptionfusion_camera_dst_type_fusion_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_camera_dst_type_fusion_param.hpp"
namespace apollo::perception::fusion{
	typedef apollo_msgs::msg::ApolloperceptionfusionCameraDstTypeFusionParam CameraDstTypeFusionParam;
}
#include "apollo_msgs/msg/apolloperceptionfusion_lidar_dst_type_fusion_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_lidar_dst_type_fusion_param.hpp"
namespace apollo::perception::fusion{
	typedef apollo_msgs::msg::ApolloperceptionfusionLidarDstTypeFusionParam LidarDstTypeFusionParam;
}
#include "apollo_msgs/msg/apolloperceptionfusion_dst_type_fusion_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_dst_type_fusion_config.hpp"
namespace apollo::perception::fusion{
	typedef apollo_msgs::msg::ApolloperceptionfusionDstTypeFusionConfig DstTypeFusionConfig;
}