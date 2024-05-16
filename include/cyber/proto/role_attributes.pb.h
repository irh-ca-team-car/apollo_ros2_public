#pragma once
#include "cyber/proto/qos_profile.pb.h"
#include "apollo_msgs/msg/apollocyberproto_socket_addr.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_socket_addr.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoSocketAddr SocketAddr;
}
#include "apollo_msgs/msg/apollocyberproto_role_attributes.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_role_attributes.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoRoleAttributes RoleAttributes;
}