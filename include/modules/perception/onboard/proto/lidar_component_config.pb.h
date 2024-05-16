#pragma once
#include "apollo_msgs/msg/apolloperceptiononboard_lidar_segmentation_component_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_lidar_segmentation_component_config.hpp"
namespace apollo::perception::onboard{
	typedef apollo_msgs::msg::ApolloperceptiononboardLidarSegmentationComponentConfig LidarSegmentationComponentConfig;
}
#include "apollo_msgs/msg/apolloperceptiononboard_lidar_detection_component_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_lidar_detection_component_config.hpp"
namespace apollo::perception::onboard{
	typedef apollo_msgs::msg::ApolloperceptiononboardLidarDetectionComponentConfig LidarDetectionComponentConfig;
}
#include "apollo_msgs/msg/apolloperceptiononboard_lidar_recognition_component_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_lidar_recognition_component_config.hpp"
namespace apollo::perception::onboard{
	typedef apollo_msgs::msg::ApolloperceptiononboardLidarRecognitionComponentConfig LidarRecognitionComponentConfig;
}