#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/direction.pb.h"
#include "apollo_msgs/msg/apollov2x_single_traffic_light.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_single_traffic_light.hpp"
#include "apollo_msgs/msg/apollov2x_road_traffic_light.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_road_traffic_light.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xRoadTrafficLight RoadTrafficLight;
}
#include "apollo_msgs/msg/apollov2x_intersection_traffic_light_data.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_intersection_traffic_light_data.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xIntersectionTrafficLightData IntersectionTrafficLightData;
}
namespace apollo::v2x::SingleTrafficLight{
	enum Color {
		UNKNOWN = 0,
		RED = 1,
		YELLOW = 2,
		GREEN = 3,
		BLACK = 4,
		FLASH_GREEN = 5
	};
}
namespace apollo::v2x::SingleTrafficLight{
	enum Type {
		STRAIGHT = 0,
		LEFT = 1,
		RIGHT = 2,
		U_TURN = 3
	};
}