#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerayolo_yolo_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_yolo_param.hpp"
namespace apollo::perception::camera::yolo{
	typedef apollo_msgs::msg::ApolloperceptioncamerayoloYoloParam YoloParam;
}
#include "apollo_msgs/msg/apolloperceptioncamerayolo_model_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_model_param.hpp"
namespace apollo::perception::camera::yolo{
	typedef apollo_msgs::msg::ApolloperceptioncamerayoloModelParam ModelParam;
}
#include "apollo_msgs/msg/apolloperceptioncamerayolo_network_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_network_param.hpp"
namespace apollo::perception::camera::yolo{
	typedef apollo_msgs::msg::ApolloperceptioncamerayoloNetworkParam NetworkParam;
}
#include "apollo_msgs/msg/apolloperceptioncamerayolo_nms_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_nms_param.hpp"
namespace apollo::perception::camera::yolo{
	typedef apollo_msgs::msg::ApolloperceptioncamerayoloNMSParam NMSParam;
}
#include "apollo_msgs/msg/apolloperceptioncamerayolo_b_box_statistics.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_b_box_statistics.hpp"
namespace apollo::perception::camera::yolo{
	typedef apollo_msgs::msg::ApolloperceptioncamerayoloBBoxStatistics BBoxStatistics;
}
#include "apollo_msgs/msg/apolloperceptioncamerayolo_dimension_statistics.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_dimension_statistics.hpp"
namespace apollo::perception::camera::yolo{
	typedef apollo_msgs::msg::ApolloperceptioncamerayoloDimensionStatistics DimensionStatistics;
}