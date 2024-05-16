#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/routing/proto/routing.pb.h"
#include "apollo_msgs/msg/apollotask_manager_cycle_routing_task.hpp"
#include "adapter/serialization/apollo_msgs/apollotask_manager_cycle_routing_task.hpp"
namespace apollo::task_manager{
	typedef apollo_msgs::msg::ApollotaskManagerCycleRoutingTask CycleRoutingTask;
}
#include "apollo_msgs/msg/apollotask_manager_task.hpp"
#include "adapter/serialization/apollo_msgs/apollotask_manager_task.hpp"
namespace apollo::task_manager{
	typedef apollo_msgs::msg::ApollotaskManagerTask Task;
}
namespace apollo::task_manager{
	enum TaskType {
		CYCLE_ROUTING = 0
	};
}