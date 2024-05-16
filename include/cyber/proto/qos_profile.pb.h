#pragma once
#include "apollo_msgs/msg/apollocyberproto_qos_profile.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_qos_profile.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoQosProfile QosProfile;
}
namespace apollo::cyber::proto{
	enum QosHistoryPolicy {
		HISTORY_SYSTEM_DEFAULT = 0,
		HISTORY_KEEP_LAST = 1,
		HISTORY_KEEP_ALL = 2
	};
}
namespace apollo::cyber::proto{
	enum QosReliabilityPolicy {
		RELIABILITY_SYSTEM_DEFAULT = 0,
		RELIABILITY_RELIABLE = 1,
		RELIABILITY_BEST_EFFORT = 2
	};
}
namespace apollo::cyber::proto{
	enum QosDurabilityPolicy {
		DURABILITY_SYSTEM_DEFAULT = 0,
		DURABILITY_TRANSIENT_LOCAL = 1,
		DURABILITY_VOLATILE = 2
	};
}