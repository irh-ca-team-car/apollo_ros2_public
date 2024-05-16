#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodriversrobosense_robosense_scan_packet.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversrobosense_robosense_scan_packet.hpp"
namespace apollo::drivers::robosense{
	typedef apollo_msgs::msg::ApollodriversrobosenseRobosenseScanPacket RobosenseScanPacket;
}
#include "apollo_msgs/msg/apollodriversrobosense_robosense_scan.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversrobosense_robosense_scan.hpp"
namespace apollo::drivers::robosense{
	typedef apollo_msgs::msg::ApollodriversrobosenseRobosenseScan RobosenseScan;
}