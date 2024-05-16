#pragma once
#include "apollo_msgs/msg/apollodbmap_db_point.hpp"
#include "adapter/serialization/apollo_msgs/apollodbmap_db_point.hpp"
namespace apollo::dbmap{
	typedef apollo_msgs::msg::ApollodbmapDBPoint DBPoint;
}
#include "apollo_msgs/msg/apollodbmap_db_line.hpp"
#include "adapter/serialization/apollo_msgs/apollodbmap_db_line.hpp"
namespace apollo::dbmap{
	typedef apollo_msgs::msg::ApollodbmapDBLine DBLine;
}
#include "apollo_msgs/msg/apollodbmap_db_neighbour_segment.hpp"
#include "adapter/serialization/apollo_msgs/apollodbmap_db_neighbour_segment.hpp"
namespace apollo::dbmap{
	typedef apollo_msgs::msg::ApollodbmapDBNeighbourSegment DBNeighbourSegment;
}
#include "apollo_msgs/msg/apollodbmap_db_neighbour_path.hpp"
#include "adapter/serialization/apollo_msgs/apollodbmap_db_neighbour_path.hpp"
namespace apollo::dbmap{
	typedef apollo_msgs::msg::ApollodbmapDBNeighbourPath DBNeighbourPath;
}
#include "apollo_msgs/msg/apollodbmap_db_path.hpp"
#include "adapter/serialization/apollo_msgs/apollodbmap_db_path.hpp"
namespace apollo::dbmap{
	typedef apollo_msgs::msg::ApollodbmapDBPath DBPath;
}
#include "apollo_msgs/msg/apollodbmap_db_map.hpp"
#include "adapter/serialization/apollo_msgs/apollodbmap_db_map.hpp"
namespace apollo::dbmap{
	typedef apollo_msgs::msg::ApollodbmapDBMap DBMap;
}