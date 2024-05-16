#pragma once
#include "apollo_msgs/msg/apollostorytelling_topic_config.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_topic_config.hpp"
namespace apollo::storytelling{
	typedef apollo_msgs::msg::ApollostorytellingTopicConfig TopicConfig;
}
#include "apollo_msgs/msg/apollostorytelling_storytelling_config.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_storytelling_config.hpp"
namespace apollo::storytelling{
	typedef apollo_msgs::msg::ApollostorytellingStorytellingConfig StorytellingConfig;
}