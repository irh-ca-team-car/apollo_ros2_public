#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollomonitor_component_status.hpp"
#include "adapter/serialization/apollo_msgs/apollomonitor_component_status.hpp"
#include "apollo_msgs/msg/apollomonitor_component.hpp"
#include "adapter/serialization/apollo_msgs/apollomonitor_component.hpp"
namespace apollo::monitor{
	typedef apollo_msgs::msg::ApollomonitorComponent Component;
}
#include "apollo_msgs/msg/apollomonitor_system_status.hpp"
#include "adapter/serialization/apollo_msgs/apollomonitor_system_status.hpp"
namespace apollo::monitor::ComponentStatus{
	enum Status {
		UNKNOWN = 0,
		OK = 1,
		WARN = 2,
		ERROR = 3,
		FATAL = 4
	};
}