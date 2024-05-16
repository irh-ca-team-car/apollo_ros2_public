#pragma once
#include "modules/common/proto/error_code.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/map/proto/map_lane.pb.h"
#include "apollo_msgs/msg/apolloperception_b_box2_d.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_b_box2_d.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionBBox2D BBox2D;
}
#include "apollo_msgs/msg/apolloperception_light_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_light_status.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionLightStatus LightStatus;
}
#include "apollo_msgs/msg/apolloperception_v2_x_information.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_v2_x_information.hpp"
#include "apollo_msgs/msg/apolloperception_sensor_measurement.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_sensor_measurement.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionSensorMeasurement SensorMeasurement;
}
#include "apollo_msgs/msg/apolloperception_trajectory.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_trajectory.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionTrajectory Trajectory;
}
#include "apollo_msgs/msg/apolloperception_debug_message.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_debug_message.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionDebugMessage DebugMessage;
}
#include "apollo_msgs/msg/apolloperception_perception_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_perception_obstacle.hpp"
#include "apollo_msgs/msg/apolloperception_lane_marker.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_lane_marker.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionLaneMarker LaneMarker;
}
#include "apollo_msgs/msg/apolloperception_lane_markers.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_lane_markers.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionLaneMarkers LaneMarkers;
}
#include "apollo_msgs/msg/apolloperception_cipv_info.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_cipv_info.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionCIPVInfo CIPVInfo;
}
#include "apollo_msgs/msg/apolloperception_perception_obstacles.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_perception_obstacles.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionPerceptionObstacles PerceptionObstacles;
}
namespace apollo::perception::V2XInformation{
	enum V2XType {
		NONE = 0,
		ZOMBIES_CAR = 1,
		BLIND_ZONE = 2
	};
}
namespace apollo::perception::PerceptionObstacle{
	enum Type {
		UNKNOWN = 0,
		UNKNOWN_MOVABLE = 1,
		UNKNOWN_UNMOVABLE = 2,
		PEDESTRIAN = 3,  // Pedestrian, usually determined by moving behavior.
		BICYCLE = 4,     // bike, motor bike
		VEHICLE = 5     // Passenger car or truck.
	};
}
namespace apollo::perception::PerceptionObstacle{
	enum ConfidenceType {
		CONFIDENCE_UNKNOWN = 0,
		CONFIDENCE_CNN = 1,
		CONFIDENCE_RADAR = 2
	};
}
namespace apollo::perception::PerceptionObstacle{
	enum SubType {
		ST_UNKNOWN = 0,
		ST_UNKNOWN_MOVABLE = 1,
		ST_UNKNOWN_UNMOVABLE = 2,
		ST_CAR = 3,
		ST_VAN = 4,
		ST_TRUCK = 5,
		ST_BUS = 6,
		ST_CYCLIST = 7,
		ST_MOTORCYCLIST = 8,
		ST_TRICYCLIST = 9,
		ST_PEDESTRIAN = 10,
		ST_TRAFFICCONE = 11
	};
}
namespace apollo::perception::PerceptionObstacle{
	enum Source {
		HOST_VEHICLE = 0,
		V2X = 1
	};
}

#include "modules/perception/proto/perception_obstacle_name.pb.h"