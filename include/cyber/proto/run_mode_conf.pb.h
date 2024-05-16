#pragma once
#include "apollo_msgs/msg/apollocyberproto_run_mode_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_run_mode_conf.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoRunModeConf RunModeConf;
}
namespace apollo::cyber::proto{
	enum RunMode {
		MODE_REALITY = 0,
		MODE_SIMULATION = 1
	};
}
namespace apollo::cyber::proto{
	enum ClockMode {
		MODE_CYBER = 0,
		MODE_MOCK = 1
	};
}