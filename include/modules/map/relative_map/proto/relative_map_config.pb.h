#pragma once
#include "apollo_msgs/msg/apollorelative_map_map_generation_param.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_map_generation_param.hpp"
namespace apollo::relative_map{
	typedef apollo_msgs::msg::ApollorelativeMapMapGenerationParam MapGenerationParam;
}
#include "apollo_msgs/msg/apollorelative_map_navigation_lane_config.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_navigation_lane_config.hpp"
#include "apollo_msgs/msg/apollorelative_map_relative_map_config.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_relative_map_config.hpp"
namespace apollo::relative_map{
	typedef apollo_msgs::msg::ApollorelativeMapRelativeMapConfig RelativeMapConfig;
}
namespace apollo::relative_map::NavigationLaneConfig{
	enum LaneSource {
		PERCEPTION = 1,
		OFFLINE_GENERATED = 2
	};
}