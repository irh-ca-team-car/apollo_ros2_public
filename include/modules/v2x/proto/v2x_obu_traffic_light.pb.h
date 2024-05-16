#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/v2x/proto/v2x_traffic_light.pb.h"
#include "apollo_msgs/msg/apollov2xobu_single_traffic_light.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xobu_single_traffic_light.hpp"
#include "apollo_msgs/msg/apollov2xobu_lane_traffic_light.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xobu_lane_traffic_light.hpp"
namespace apollo::v2x::obu{
	typedef apollo_msgs::msg::Apollov2xobuLaneTrafficLight LaneTrafficLight;
}
#include "apollo_msgs/msg/apollov2xobu_road_traffic_light.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xobu_road_traffic_light.hpp"
namespace apollo::v2x::obu{
	typedef apollo_msgs::msg::Apollov2xobuRoadTrafficLight RoadTrafficLight;
}
#include "apollo_msgs/msg/apollov2xobu_obu_traffic_light.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xobu_obu_traffic_light.hpp"
namespace apollo::v2x::obu{
	typedef apollo_msgs::msg::Apollov2xobuObuTrafficLight ObuTrafficLight;
}
namespace apollo::v2x::obu::SingleTrafficLight{
	enum Type {
		STRAIGHT = 1,
		LEFT = 2,
		RIGHT = 3,
		U_TURN = 4
	};
}