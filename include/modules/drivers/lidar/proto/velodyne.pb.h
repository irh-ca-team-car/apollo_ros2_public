#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodriversvelodyne_velodyne_packet.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_velodyne_packet.hpp"
namespace apollo::drivers::velodyne{
	typedef apollo_msgs::msg::ApollodriversvelodyneVelodynePacket VelodynePacket;
}
#include "apollo_msgs/msg/apollodriversvelodyne_velodyne_scan.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_velodyne_scan.hpp"
namespace apollo::drivers::velodyne{
	typedef apollo_msgs::msg::ApollodriversvelodyneVelodyneScan VelodyneScan;
}
namespace apollo::drivers::velodyne{
	enum Model {
		UNKNOWN = 0,
		HDL64E_S3S = 1,
		HDL64E_S3D = 2,
		HDL64E_S2 = 3,
		HDL32E = 4,
		VLP16 = 5,
		VLP32C = 6,
		VLS128 = 7
	};
}
namespace apollo::drivers::velodyne{
	enum Mode {
		STRONGEST = 1,
		LAST = 2,
		DUAL = 3
	};
}