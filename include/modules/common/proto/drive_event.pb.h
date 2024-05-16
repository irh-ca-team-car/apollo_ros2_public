#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/localization/proto/pose.pb.h"
#include "apollo_msgs/msg/apollocommon_drive_event.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_drive_event.hpp"
namespace apollo::common::DriveEvent{
	enum Type {
		CRITICAL = 0,
		PROBLEM = 1,
		DESIRED = 2,
		OUT_OF_SCOPE = 3
	};
}