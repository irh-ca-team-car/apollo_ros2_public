#pragma once
#include "apollo_msgs/msg/vector3.hpp"
#include "adapter/serialization/apollo_msgs/vector3.hpp"
namespace {
	typedef apollo_msgs::msg::Vector3 Vector3;
}
#include "apollo_msgs/msg/vector4.hpp"
#include "adapter/serialization/apollo_msgs/vector4.hpp"
namespace {
	typedef apollo_msgs::msg::Vector4 Vector4;
}
#include "apollo_msgs/msg/quaternion.hpp"
#include "adapter/serialization/apollo_msgs/quaternion.hpp"
namespace {
	typedef apollo_msgs::msg::Quaternion Quaternion;
}
#include "apollo_msgs/msg/gps_pose.hpp"
#include "adapter/serialization/apollo_msgs/gps_pose.hpp"
namespace {
	typedef apollo_msgs::msg::GPSPose GPSPose;
}
#include "apollo_msgs/msg/camera_image.hpp"
#include "adapter/serialization/apollo_msgs/camera_image.hpp"
namespace {
	typedef apollo_msgs::msg::CameraImage CameraImage;
}
#include "apollo_msgs/msg/radar_point.hpp"
#include "adapter/serialization/apollo_msgs/radar_point.hpp"
#include "apollo_msgs/msg/frame.hpp"
#include "adapter/serialization/apollo_msgs/frame.hpp"
namespace {
	typedef apollo_msgs::msg::Frame Frame;
}
namespace ::RadarPoint{
	enum RadarType {
		FRONT = 1,
		REAR = 2
	};
}