#pragma once
#include "apollo_msgs/msg/apollorelative_map_sample_param.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_sample_param.hpp"
namespace apollo::relative_map{
	typedef apollo_msgs::msg::ApollorelativeMapSampleParam SampleParam;
}
#include "apollo_msgs/msg/apollorelative_map_navigator_config.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_navigator_config.hpp"
namespace apollo::relative_map{
	typedef apollo_msgs::msg::ApollorelativeMapNavigatorConfig NavigatorConfig;
}