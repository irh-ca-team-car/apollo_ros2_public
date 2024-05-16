#pragma once
#include "apollo_msgs/msg/apollorouting_topic_config.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_topic_config.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingTopicConfig TopicConfig;
}
#include "apollo_msgs/msg/apollorouting_routing_config.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_routing_config.hpp"
namespace apollo::routing{
	typedef apollo_msgs::msg::ApolloroutingRoutingConfig RoutingConfig;
}