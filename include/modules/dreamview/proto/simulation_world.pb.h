#pragma once
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/common/monitor_log/proto/monitor_log.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/planning/proto/planning_internal.pb.h"
#include "modules/prediction/proto/feature.pb.h"
#include "modules/routing/proto/routing.pb.h"

#include "apollo_msgs/msg/apollodreamview_decision.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_decision.hpp"
#include "apollo_msgs/msg/apollodreamview_object.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_object.hpp"
#include "apollo_msgs/msg/apollodreamview_delays_in_ms.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_delays_in_ms.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewDelaysInMs DelaysInMs;
}
#include "apollo_msgs/msg/apollodreamview_route_path.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_route_path.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewRoutePath RoutePath;
}
#include "apollo_msgs/msg/apollodreamview_latency.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_latency.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewLatency Latency;
}
#include "apollo_msgs/msg/apollodreamview_map_element_ids.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_map_element_ids.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewMapElementIds MapElementIds;
}
#include "apollo_msgs/msg/apollodreamview_control_data.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_control_data.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewControlData ControlData;
}
#include "apollo_msgs/msg/apollodreamview_notification.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_notification.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewNotification Notification;
}
#include "apollo_msgs/msg/apollodreamview_sensor_measurements.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_sensor_measurements.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewSensorMeasurements SensorMeasurements;
}
#include "apollo_msgs/msg/apollodreamview_simulation_world.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_simulation_world.hpp"
namespace apollo::dreamview::Decision{
	enum Type {
		IGNORE = 0,    // Ignore the object
		STOP = 1,      // Stop at a distance from the object
		NUDGE = 2,     // Go around the object
		YIELD = 3,     // Go after the object
		OVERTAKE = 4,  // Go before the object
		FOLLOW = 5,    // Follow the object in the same lane
		SIDEPASS = 6  // Pass the object in neighboring lane
	};
}
namespace apollo::dreamview::Decision{
	enum StopReasonCode {
		STOP_REASON_HEAD_VEHICLE = 1,
		STOP_REASON_DESTINATION = 2,
		STOP_REASON_PEDESTRIAN = 3,
		STOP_REASON_OBSTACLE = 4,
		STOP_REASON_SIGNAL = 100,
		STOP_REASON_STOP_SIGN = 101,
		STOP_REASON_YIELD_SIGN = 102,
		STOP_REASON_CLEAR_ZONE = 103,
		STOP_REASON_CROSSWALK = 104,
		STOP_REASON_EMERGENCY = 105,
		STOP_REASON_NOT_READY = 106,
		STOP_REASON_PULL_OVER = 107
	};
}
namespace apollo::dreamview::Object{
	enum DisengageType {
		DISENGAGE_NONE = 0,
		DISENGAGE_UNKNOWN = 1,
		DISENGAGE_MANUAL = 2,
		DISENGAGE_EMERGENCY = 3,
		DISENGAGE_AUTO_STEER_ONLY = 4,
		DISENGAGE_AUTO_SPEED_ONLY = 5,
		DISENGAGE_CHASSIS_ERROR = 6
	};
}
namespace apollo::dreamview::Object{
	enum Type {
		UNKNOWN = 0,
		UNKNOWN_MOVABLE = 1,
		UNKNOWN_UNMOVABLE = 2,
		PEDESTRIAN = 3,  // pedestrian, usually determined by moving behavior.
		BICYCLE = 4,     // bike, motor bike.
		VEHICLE = 5,     // passenger car or truck.
		VIRTUAL = 6,     // virtual object created by decision module.
		CIPV = 7        // closest in-path vehicle determined by perception module.
	};
}