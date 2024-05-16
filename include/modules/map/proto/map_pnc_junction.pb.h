#pragma once
#include "modules/map/proto/map_id.pb.h"
#include "modules/map/proto/map_geometry.pb.h"
#include "apollo_msgs/msg/apollohdmap_passage.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_passage.hpp"
#include "apollo_msgs/msg/apollohdmap_passage_group.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_passage_group.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapPassageGroup PassageGroup;
}
#include "apollo_msgs/msg/apollohdmap_pnc_junction.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_pnc_junction.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapPNCJunction PNCJunction;
}
namespace apollo::hdmap::Passage{
	enum Type {
		UNKNOWN = 0,
		ENTRANCE = 1,
		EXIT = 2
	};
}