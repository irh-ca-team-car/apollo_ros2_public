#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "apollo_msgs/msg/apolloperceptioncamera_lane_line_cubic_curve.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_lane_line_cubic_curve.hpp"
namespace apollo::perception::camera{
	typedef apollo_msgs::msg::ApolloperceptioncameraLaneLineCubicCurve LaneLineCubicCurve;
}
#include "apollo_msgs/msg/apolloperceptioncamera_end_points.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_end_points.hpp"
namespace apollo::perception::camera{
	typedef apollo_msgs::msg::ApolloperceptioncameraEndPoints EndPoints;
}
#include "apollo_msgs/msg/apolloperceptioncamera_camera_lane_line.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_lane_line.hpp"
namespace apollo::perception::camera{
	typedef apollo_msgs::msg::ApolloperceptioncameraCameraLaneLine CameraLaneLine;
}
#include "apollo_msgs/msg/apolloperceptioncamera_camera_calibrator.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_calibrator.hpp"
namespace apollo::perception::camera{
	typedef apollo_msgs::msg::ApolloperceptioncameraCameraCalibrator CameraCalibrator;
}
#include "apollo_msgs/msg/apolloperceptioncamera_camera_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_obstacle.hpp"
#include "apollo_msgs/msg/apolloperceptioncamera_camera_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_debug.hpp"
namespace apollo::perception::camera{
	typedef apollo_msgs::msg::ApolloperceptioncameraCameraDebug CameraDebug;
}
namespace apollo::perception::camera{
	enum CameraErrorCode {
		ERROR_NONE = 0,
		ERROR_UNKNOWN = 1
	};
}
namespace apollo::perception::camera{
	enum LaneLineType {
		WHITE_DASHED = 0,
		WHITE_SOLID = 1,
		YELLOW_DASHED = 2,
		YELLOW_SOLID = 3
	};
}
namespace apollo::perception::camera{
	enum LaneLinePositionType {
		BOLLARD_LEFT = -5,
		FOURTH_LEFT = -4,
		THIRD_LEFT = -3,
		ADJACENT_LEFT = -2,  //!< lane marking on the left side next to ego lane
		EGO_LEFT = -1,       //!< left lane marking of the ego lane
		EGO_RIGHT = 1,       //!< right lane marking of the ego lane
		ADJACENT_RIGHT = 2,  //!< lane marking on the right side next to ego lane
		THIRD_RIGHT = 3,
		FOURTH_RIGHT = 4,
		BOLLARD_RIGHT = 5,
		OTHER = 6,    //!< other types of lane
		UNKNOWN = 7  //!< background
	};
}
namespace apollo::perception::camera{
	enum LaneLineUseType {
		REAL = 0,
		VIRTUAL = 1
	};
}
namespace apollo::perception::camera::CameraObstacle{
	enum CameraType {
		UNKNOWN = 0,
		UNKNOWN_MOVABLE = 1,
		UNKNOWN_UNMOVABLE = 2,
		PEDESTRIAN = 3,  // Pedestrian, usually determined by moving behaviour.
		BICYCLE = 4,     // bike, motor bike
		VEHICLE = 5     // Passenger car or truck.
	};
}