#pragma once
#include "apollo_msgs/msg/apollotask_manager_topic_config.hpp"
#include "adapter/serialization/apollo_msgs/apollotask_manager_topic_config.hpp"
namespace apollo::task_manager{
	typedef apollo_msgs::msg::ApollotaskManagerTopicConfig TopicConfig;
}
#include "apollo_msgs/msg/apollotask_manager_task_manager_config.hpp"
#include "adapter/serialization/apollo_msgs/apollotask_manager_task_manager_config.hpp"
namespace apollo::task_manager{
	typedef apollo_msgs::msg::ApollotaskManagerTaskManagerConfig TaskManagerConfig;
}