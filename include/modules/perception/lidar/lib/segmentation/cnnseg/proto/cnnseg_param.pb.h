#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_cnn_seg_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_cnn_seg_param.hpp"
namespace apollo::perception::lidar{
	typedef apollo_msgs::msg::ApolloperceptionlidarCNNSegParam CNNSegParam;
}
#include "apollo_msgs/msg/apolloperceptionlidar_network_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_network_param.hpp"
namespace apollo::perception::lidar{
	typedef apollo_msgs::msg::ApolloperceptionlidarNetworkParam NetworkParam;
}
#include "apollo_msgs/msg/apolloperceptionlidar_feature_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_feature_param.hpp"
namespace apollo::perception::lidar{
	typedef apollo_msgs::msg::ApolloperceptionlidarFeatureParam FeatureParam;
}