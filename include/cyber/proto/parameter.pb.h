#pragma once
#include "apollo_msgs/msg/apollocyberproto_param.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_param.hpp"
#include "apollo_msgs/msg/apollocyberproto_node_name.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_node_name.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoNodeName NodeName;
}
#include "apollo_msgs/msg/apollocyberproto_param_name.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_param_name.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoParamName ParamName;
}
#include "apollo_msgs/msg/apollocyberproto_bool_result.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_bool_result.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoBoolResult BoolResult;
}
#include "apollo_msgs/msg/apollocyberproto_params.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_params.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoParams Params;
}
namespace apollo::cyber::proto{
	enum ParamType {
		NOT_SET = 0,
		BOOL = 1,
		INT = 2,
		DOUBLE = 3,
		STRING = 4,
		PROTOBUF = 5
	};
}