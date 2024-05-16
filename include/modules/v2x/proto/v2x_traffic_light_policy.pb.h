#pragma once
#include "apollo_msgs/msg/apollov2x_position2_d.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_position2_d.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xPosition2D Position2D;
}
#include "apollo_msgs/msg/apollov2x_connection.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_connection.hpp"
#include "apollo_msgs/msg/apollov2x_lane.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_lane.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xLane Lane;
}
#include "apollo_msgs/msg/apollov2x_road.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_road.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xRoad Road;
}
#include "apollo_msgs/msg/apollov2x_intersection.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_intersection.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xIntersection Intersection;
}
#include "apollo_msgs/msg/apollov2x_map.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_map.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xMap Map;
}
#include "apollo_msgs/msg/apollov2x_phase.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_phase.hpp"
#include "apollo_msgs/msg/apollov2x_intersection_state.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_intersection_state.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xIntersectionState IntersectionState;
}
#include "apollo_msgs/msg/apollov2x_spat.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_spat.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xSpat Spat;
}
#include "apollo_msgs/msg/apollov2x_policy_data.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_policy_data.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xPolicyData PolicyData;
}
namespace apollo::v2x::Connection{
	enum Type {
		STRAIGHT = 0,
		LEFT = 1,
		RIGHT = 2,
		U_TURN = 3
	};
}
namespace apollo::v2x::Phase{
	enum Color {
		UNKNOWN = 0,
		RED = 1,
		YELLOW = 2,
		GREEN = 3,
		BLACK = 4,
		FLASH_GREEN = 5
	};
}