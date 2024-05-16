#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollocommonmonitor_monitor_message_item.hpp"
#include "adapter/serialization/apollo_msgs/apollocommonmonitor_monitor_message_item.hpp"
#include "apollo_msgs/msg/apollocommonmonitor_monitor_message.hpp"
#include "adapter/serialization/apollo_msgs/apollocommonmonitor_monitor_message.hpp"
namespace apollo::common::monitor{
	typedef apollo_msgs::msg::ApollocommonmonitorMonitorMessage MonitorMessage;
}
namespace apollo::common::monitor::MonitorMessageItem{
	enum MessageSource {
		UNKNOWN = 1,
		CANBUS = 2,
		CONTROL = 3,
		DECISION = 4,
		LOCALIZATION = 5,
		PLANNING = 6,
		PREDICTION = 7,
		SIMULATOR = 8,
		HWSYS = 9,
		ROUTING = 10,
		MONITOR = 11,
		HMI = 12,
		RELATIVE_MAP = 13,
		GNSS = 14,
		CONTI_RADAR = 15,
		RACOBIT_RADAR = 16,
		ULTRASONIC_RADAR = 17,
		MOBILEYE = 18,
		DELPHI_ESR = 19,
		STORYTELLING = 20
	};
}
namespace apollo::common::monitor::MonitorMessageItem{
	enum LogLevel {
		INFO = 0,
		WARN = 1,
		ERROR = 2,
		FATAL = 3
	};
}