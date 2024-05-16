#pragma once
#include "apollo_msgs/msg/apollocyberproto_perf_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_perf_conf.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoPerfConf PerfConf;
}
namespace apollo::cyber::proto{
	enum PerfType {
		SCHED = 1,
		TRANSPORT = 2,
		DATA_CACHE = 3,
		ALL = 4
	};
}