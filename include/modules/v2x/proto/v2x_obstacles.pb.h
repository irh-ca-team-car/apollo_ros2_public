#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/error_code.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "apollo_msgs/msg/apollov2x_point.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_point.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xPoint Point;
}
#include "apollo_msgs/msg/apollov2x_mini_area_map.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_mini_area_map.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xMiniAreaMap MiniAreaMap;
}
#include "apollo_msgs/msg/apollov2x_abnormal_information.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_abnormal_information.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xAbnormalInformation AbnormalInformation;
}
#include "apollo_msgs/msg/apollov2x_v2_x_information.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_v2_x_information.hpp"
#include "apollo_msgs/msg/apollov2x_v2_x_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_v2_x_obstacle.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xV2XObstacle V2XObstacle;
}
#include "apollo_msgs/msg/apollov2x_v2_x_obstacles.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_v2_x_obstacles.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xV2XObstacles V2XObstacles;
}
namespace apollo::v2x::V2XInformation{
	enum V2XType {
		NONE = 0,
		ZOMBIES_CAR = 1,
		BLIND_ZONE = 2
	};
}