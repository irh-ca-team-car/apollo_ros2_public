#pragma once
#include "apollo_msgs/msg/apolloperception_sensor_meta.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_sensor_meta.hpp"
#include "apollo_msgs/msg/apolloperception_multi_sensor_meta.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_multi_sensor_meta.hpp"
namespace apollo::perception{
	typedef apollo_msgs::msg::ApolloperceptionMultiSensorMeta MultiSensorMeta;
}
namespace apollo::perception::SensorMeta{
	enum SensorType {
		UNKNOWN_SENSOR_TYPE = -1,
		VELODYNE_64 = 0,
		VELODYNE_32 = 1,
		VELODYNE_16 = 2,
		LDLIDAR_4 = 3,
		LDLIDAR_1 = 4,
		SHORT_RANGE_RADAR = 5,
		LONG_RANGE_RADAR = 6,
		MONOCULAR_CAMERA = 7,
		STEREO_CAMERA = 8,
		ULTRASONIC = 9,
		VELODYNE_128 = 10
	};
}
namespace apollo::perception::SensorMeta{
	enum SensorOrientation {
		FRONT = 0,
		LEFT_FORWARD = 1,
		LEFT = 2,
		LEFT_BACKWARD = 3,
		REAR = 4,
		RIGHT_BACKWARD = 5,
		RIGHT = 6,
		RIGHT_FORWARD = 7,
		PANORAMIC = 8
	};
}