#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "modules/map/proto/map_geometry.pb.h"
#include "modules/map/proto/map_id.pb.h"
#include "apollo_msgs/msg/apollohdmap_subsignal.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_subsignal.hpp"
#include "apollo_msgs/msg/apollohdmap_sign_info.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_sign_info.hpp"
#include "apollo_msgs/msg/apollohdmap_signal.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_signal.hpp"
namespace apollo::hdmap::Subsignal{
	enum Type {
		UNKNOWN = 1,
		CIRCLE = 2,
		ARROW_LEFT = 3,
		ARROW_FORWARD = 4,
		ARROW_RIGHT = 5,
		ARROW_LEFT_AND_FORWARD = 6,
		ARROW_RIGHT_AND_FORWARD = 7,
		ARROW_U_TURN = 8
	};
}
namespace apollo::hdmap::SignInfo{
	enum Type {
		None = 0,
		NO_RIGHT_TURN_ON_RED = 1
	};
}
namespace apollo::hdmap::Signal{
	enum Type {
		UNKNOWN = 1,
		MIX_2_HORIZONTAL = 2,
		MIX_2_VERTICAL = 3,
		MIX_3_HORIZONTAL = 4,
		MIX_3_VERTICAL = 5,
		SINGLE = 6
	};
}