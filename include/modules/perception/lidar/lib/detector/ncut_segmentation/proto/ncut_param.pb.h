#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_n_cut_segmentation_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_n_cut_segmentation_param.hpp"
namespace apollo::perception::lidar{
	typedef apollo_msgs::msg::ApolloperceptionlidarNCutSegmentationParam NCutSegmentationParam;
}
#include "apollo_msgs/msg/apolloperceptionlidar_n_cut_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_n_cut_param.hpp"
namespace apollo::perception::lidar{
	typedef apollo_msgs::msg::ApolloperceptionlidarNCutParam NCutParam;
}