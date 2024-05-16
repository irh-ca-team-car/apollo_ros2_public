#pragma once
#include "modules/map/proto/map_clear_area.pb.h"
#include "modules/map/proto/map_crosswalk.pb.h"
#include "modules/map/proto/map_junction.pb.h"
#include "modules/map/proto/map_lane.pb.h"
#include "modules/map/proto/map_overlap.pb.h"
#include "modules/map/proto/map_signal.pb.h"
#include "modules/map/proto/map_speed_bump.pb.h"
#include "modules/map/proto/map_stop_sign.pb.h"
#include "modules/map/proto/map_yield_sign.pb.h"
#include "modules/map/proto/map_road.pb.h"
#include "modules/map/proto/map_parking_space.pb.h"
#include "modules/map/proto/map_pnc_junction.pb.h"
#include "modules/map/proto/map_rsu.pb.h"
#include "apollo_msgs/msg/apollohdmap_projection.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_projection.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapProjection Projection;
}
#include "apollo_msgs/msg/apollohdmap_header.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_header.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapHeader Header;
}
#include "apollo_msgs/msg/apollohdmap_map.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_map.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapMap Map;
}