#pragma once
#include "apollo_msgs/msg/apollobridge_udp_bridge_sender_remote_info.hpp"
#include "adapter/serialization/apollo_msgs/apollobridge_udp_bridge_sender_remote_info.hpp"
namespace apollo::bridge{
	typedef apollo_msgs::msg::ApollobridgeUDPBridgeSenderRemoteInfo UDPBridgeSenderRemoteInfo;
}
#include "apollo_msgs/msg/apollobridge_udp_bridge_receiver_remote_info.hpp"
#include "adapter/serialization/apollo_msgs/apollobridge_udp_bridge_receiver_remote_info.hpp"
namespace apollo::bridge{
	typedef apollo_msgs::msg::ApollobridgeUDPBridgeReceiverRemoteInfo UDPBridgeReceiverRemoteInfo;
}