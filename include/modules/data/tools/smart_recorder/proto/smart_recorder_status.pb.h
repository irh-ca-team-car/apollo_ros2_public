#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodata_smart_recorder_status.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_smart_recorder_status.hpp"
namespace apollo::data{
	typedef apollo_msgs::msg::ApollodataSmartRecorderStatus SmartRecorderStatus;
}
namespace apollo::data{
	enum RecordingState {
		STOPPED = 0,
		RECORDING = 1,
		TERMINATING = 2
	};
}