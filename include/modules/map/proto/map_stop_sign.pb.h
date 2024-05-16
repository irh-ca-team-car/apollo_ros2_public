#pragma once
#include "modules/map/proto/map_id.pb.h"
#include "modules/map/proto/map_geometry.pb.h"
#include "apollo_msgs/msg/apollohdmap_stop_sign.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_stop_sign.hpp"
namespace apollo::hdmap::StopSign{
	enum StopType {
		UNKNOWN = 0,
		ONE_WAY = 1,
		TWO_WAY = 2,
		THREE_WAY = 3,
		FOUR_WAY = 4,
		ALL_WAY = 5
	};
}