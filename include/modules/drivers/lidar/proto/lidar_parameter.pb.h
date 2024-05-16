#pragma once
#include "apollo_msgs/msg/apollodriverslidar_lidar_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apollodriverslidar_lidar_parameter.hpp"
namespace apollo::drivers::lidar::LidarParameter{
	enum LidarBrand {
		VELODYNE = 0,
		HESAI = 1,
		ROBOSENSE = 2
	};
}
namespace apollo::drivers::lidar::LidarParameter{
	enum LidarChannelId {
		CHANNEL_ID_ZERO = 0,
		CHANNEL_ID_ONE = 1,
		CHANNEL_ID_TWO = 2,
		CHANNEL_ID_THREE = 3
	};
}