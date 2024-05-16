#pragma once
#include "modules/map/proto/map_lane.pb.h"

namespace apollo::hdmap::LaneBoundaryType{
	std::string Type_Name(Type val);
}
namespace apollo::hdmap::Lane{
	std::string LaneType_Name(LaneType val);
}
namespace apollo::hdmap::Lane{
	std::string LaneTurn_Name(LaneTurn val);
}
namespace apollo::hdmap::Lane{
	std::string LaneDirection_Name(LaneDirection val);
}

#include "modules/map/proto/map_lane_name.pb.h"