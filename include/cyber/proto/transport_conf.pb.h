#pragma once
#include "apollo_msgs/msg/apollocyberproto_shm_multicast_locator.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_shm_multicast_locator.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoShmMulticastLocator ShmMulticastLocator;
}
#include "apollo_msgs/msg/apollocyberproto_shm_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_shm_conf.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoShmConf ShmConf;
}
#include "apollo_msgs/msg/apollocyberproto_rtps_participant_attr.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_rtps_participant_attr.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoRtpsParticipantAttr RtpsParticipantAttr;
}
#include "apollo_msgs/msg/apollocyberproto_communication_mode.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_communication_mode.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoCommunicationMode CommunicationMode;
}
#include "apollo_msgs/msg/apollocyberproto_resource_limit.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_resource_limit.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoResourceLimit ResourceLimit;
}
#include "apollo_msgs/msg/apollocyberproto_transport_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_transport_conf.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoTransportConf TransportConf;
}
namespace apollo::cyber::proto{
	enum OptionalMode {
		HYBRID = 0,
		INTRA = 1,
		SHM = 2,
		RTPS = 3
	};
}