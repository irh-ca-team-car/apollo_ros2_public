#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_smoke_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_smoke_param.hpp"
namespace apollo::perception::camera::smoke{
	typedef apollo_msgs::msg::ApolloperceptioncamerasmokeSmokeParam SmokeParam;
}
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_model_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_model_param.hpp"
namespace apollo::perception::camera::smoke{
	typedef apollo_msgs::msg::ApolloperceptioncamerasmokeModelParam ModelParam;
}
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_network_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_network_param.hpp"
namespace apollo::perception::camera::smoke{
	typedef apollo_msgs::msg::ApolloperceptioncamerasmokeNetworkParam NetworkParam;
}
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_nms_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_nms_param.hpp"
namespace apollo::perception::camera::smoke{
	typedef apollo_msgs::msg::ApolloperceptioncamerasmokeNMSParam NMSParam;
}
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_b_box_statistics.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_b_box_statistics.hpp"
namespace apollo::perception::camera::smoke{
	typedef apollo_msgs::msg::ApolloperceptioncamerasmokeBBoxStatistics BBoxStatistics;
}
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_dimension_statistics.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_dimension_statistics.hpp"
namespace apollo::perception::camera::smoke{
	typedef apollo_msgs::msg::ApolloperceptioncamerasmokeDimensionStatistics DimensionStatistics;
}