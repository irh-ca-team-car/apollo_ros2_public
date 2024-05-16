#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollov2x_id.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_id.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xId Id;
}
#include "apollo_msgs/msg/apollov2x_junction.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_junction.hpp"
namespace apollo::v2x::Junction{
	enum Type {
		UNKNOWN = 0,
		IN_ROAD = 1,
		CROSS_ROAD = 2
	};
}
namespace apollo::v2x::Junction{
	enum EdgeType {
		PHYSICAL = 0,
		VIRTUAL = 1
	};
}