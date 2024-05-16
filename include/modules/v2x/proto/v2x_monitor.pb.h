#pragma once
#include "apollo_msgs/msg/apollov2x_obu_alarm.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_obu_alarm.hpp"
namespace apollo::v2x{
	typedef apollo_msgs::msg::Apollov2xObuAlarm ObuAlarm;
}
namespace apollo::v2x{
	enum ErrorCode {
		LTEV = 500,
		NET = 501,
		CPU = 502,
		MEM = 503,
		GPS = 504,
		MAP = 510,
		SPAT = 511,
		OBUID = 999
	};
}