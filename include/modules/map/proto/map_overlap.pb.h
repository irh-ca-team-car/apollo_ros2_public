#pragma once
#include "modules/map/proto/map_id.pb.h"
#include "modules/map/proto/map_geometry.pb.h"
#include "apollo_msgs/msg/apollohdmap_lane_overlap_info.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_lane_overlap_info.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapLaneOverlapInfo LaneOverlapInfo;
}
#include "apollo_msgs/msg/apollohdmap_crosswalk_overlap_info.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_crosswalk_overlap_info.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapCrosswalkOverlapInfo CrosswalkOverlapInfo;
}
#include "apollo_msgs/msg/apollohdmap_region_overlap_info.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_region_overlap_info.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapRegionOverlapInfo RegionOverlapInfo;
}
#include "apollo_msgs/msg/apollohdmap_object_overlap_info.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_object_overlap_info.hpp"
#include "apollo_msgs/msg/apollohdmap_overlap.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_overlap.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapOverlap Overlap;
}