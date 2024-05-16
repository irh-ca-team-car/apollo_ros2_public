#pragma once
#include "cyber/proto/role_attributes.pb.h"
#include "apollo_msgs/msg/apollocyberproto_change_msg.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_change_msg.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChangeMsg ChangeMsg;
}
namespace apollo::cyber::proto{
	enum ChangeType {
		CHANGE_NODE = 1,
		CHANGE_CHANNEL = 2,
		CHANGE_SERVICE = 3,
		CHANGE_PARTICIPANT = 4
	};
}
namespace apollo::cyber::proto{
	enum OperateType {
		OPT_JOIN = 1,
		OPT_LEAVE = 2
	};
}
namespace apollo::cyber::proto{
	enum RoleType {
		ROLE_NODE = 1,
		ROLE_WRITER = 2,
		ROLE_READER = 3,
		ROLE_SERVER = 4,
		ROLE_CLIENT = 5,
		ROLE_PARTICIPANT = 6
	};
}