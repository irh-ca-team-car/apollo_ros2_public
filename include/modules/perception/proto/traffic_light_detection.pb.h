#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apolloperception_traffic_light_box.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light_box.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionTrafficLightBox TrafficLightBox;
}
#include "apollo_msgs/msg/apolloperception_traffic_light_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light_debug.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionTrafficLightDebug TrafficLightDebug;
}
#include "apollo_msgs/msg/apolloperception_traffic_light.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light.hpp"
#include "apollo_msgs/msg/apolloperception_traffic_light_detection.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light_detection.hpp"
namespace apollo::perception::TrafficLight{
	enum Color {
		UNKNOWN = 0,
		RED = 1,
		YELLOW = 2,
		GREEN = 3,
		BLACK = 4
	};
}
namespace apollo::perception::TrafficLightDetection{
	enum CameraID {
		CAMERA_FRONT_LONG = 0,
		CAMERA_FRONT_NARROW = 1,
		CAMERA_FRONT_SHORT = 2,
		CAMERA_FRONT_WIDE = 3
	};
}