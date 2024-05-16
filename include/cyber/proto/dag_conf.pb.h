#pragma once
#include "cyber/proto/component_conf.pb.h"
#include "apollo_msgs/msg/apollocyberproto_component_info.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_component_info.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoComponentInfo ComponentInfo;
}
#include "apollo_msgs/msg/apollocyberproto_timer_component_info.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_timer_component_info.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoTimerComponentInfo TimerComponentInfo;
}
#include "apollo_msgs/msg/apollocyberproto_module_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_module_config.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoModuleConfig ModuleConfig;
}
#include "apollo_msgs/msg/apollocyberproto_dag_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_dag_config.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoDagConfig DagConfig;
}