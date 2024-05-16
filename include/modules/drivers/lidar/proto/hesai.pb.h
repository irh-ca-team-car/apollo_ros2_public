#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodrivershesai_hesai_scan_packet.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivershesai_hesai_scan_packet.hpp"
namespace apollo::drivers::hesai{
	typedef apollo_msgs::msg::ApollodrivershesaiHesaiScanPacket HesaiScanPacket;
}
#include "apollo_msgs/msg/apollodrivershesai_hesai_scan.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivershesai_hesai_scan.hpp"
namespace apollo::drivers::hesai{
	typedef apollo_msgs::msg::ApollodrivershesaiHesaiScan HesaiScan;
}
namespace apollo::drivers::hesai{
	enum Model {
		UNKNOWN = 0,
		HESAI40P = 1,
		HESAI64 = 2
	};
}