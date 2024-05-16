#pragma once
#include "apollo_msgs/msg/apollocommonadapter_adapter_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocommonadapter_adapter_config.hpp"
#include "apollo_msgs/msg/apollocommonadapter_adapter_manager_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocommonadapter_adapter_manager_config.hpp"
namespace apollo::common::adapter{
	typedef apollo_msgs::msg::ApollocommonadapterAdapterManagerConfig AdapterManagerConfig;
}
namespace apollo::common::adapter::AdapterConfig{
	enum MessageType {
		POINT_CLOUD = 1,
		VLP16_POINT_CLOUD = 58,
		GPS = 2,
		IMU = 3,
		CHASSIS = 4,
		LOCALIZATION = 5,
		PLANNING_TRAJECTORY = 6,
		MONITOR = 7,
		PAD = 8,
		CONTROL_COMMAND = 9,
		PREDICTION = 10,
		PERCEPTION_OBSTACLES = 11,
		TRAFFIC_LIGHT_DETECTION = 12,
		CHASSIS_DETAIL = 13,
		DECISION = 14 ,
		CANBUS = 15,
		ROUTING_REQUEST = 16,
		ROUTING_RESPONSE = 17,
		RELATIVE_ODOMETRY = 18,
		INS_STAT = 19,
		HMI_COMMAND = 20 ,
		MOBILEYE = 21,
		DELPHIESR = 22,
		COMPRESSED_IMAGE = 23,
		SYSTEM_STATUS = 24,
		INS_STATUS = 25,
		GNSS_STATUS = 26,
		CONTI_RADAR = 27,
		IMAGE_SHORT = 28,
		IMAGE_LONG = 29,
		DRIVE_EVENT = 30,
		GNSS_RTK_OBS = 31,
		GNSS_RTK_EPH = 32,
		GNSS_BEST_POSE = 33,
		LOCALIZATION_MSF_GNSS = 34,
		LOCALIZATION_MSF_LIDAR = 35,
		LOCALIZATION_MSF_SINS_PVA = 36,
		RAW_IMU = 37,
		LOCALIZATION_MSF_STATUS = 38,
		STATIC_INFO = 39,
		RELATIVE_MAP = 40,
		NAVIGATION = 41,
		ULTRASONIC_RADAR = 42,
		AUDIO_CAPTURE = 43,
		IMAGE_FRONT = 45,
		PANDORA_POINT_CLOUD = 46,
		PANDORA_CAMERA_FRONT_COLOR = 47,
		PANDORA_CAMERA_RIGHT_GRAY = 48,
		PANDORA_CAMERA_LEFT_GRAY = 49,
		PANDORA_CAMERA_FRONT_GRAY = 50,
		PANDORA_CAMERA_BACK_GRAY = 51,
		PERCEPTION_LANE_MASK = 52,
		GUARDIAN = 53,
		GNSS_RAW_DATA = 54,
		STREAM_STATUS = 55,
		GNSS_HEADING = 56,
		RTCM_DATA = 57,
		RACOBIT_RADAR = 59,
		// velodyne fusion configs
		POINT_CLOUD_DENSE = 60,
		POINT_CLOUD_DENSE_RAW = 61,
		VELODYNE_SCAN_DENSE = 62,
		
		POINT_CLOUD_SPARSE_1 = 63,
		POINT_CLOUD_SPARSE_RAW_1 = 64,
		VELODYNE_SCAN_SPARSE_1 = 65,
		
		POINT_CLOUD_SPARSE_2 = 66,
		POINT_CLOUD_SPARSE_RAW_2 = 67,
		VELODYNE_SCAN_SPARSE_2 = 68,
		
		POINT_CLOUD_SPARSE_3 = 69,
		POINT_CLOUD_SPARSE_RAW_3 = 70,
		VELODYNE_SCAN_SPARSE_3 = 71,
		
		CAMERA_IMAGE_LONG = 72,
		CAMERA_IMAGE_SHORT = 73,
		
		PLANNING_PAD = 74,
		
		STORYTELLING = 75
	};
}
namespace apollo::common::adapter::AdapterConfig{
	enum Mode {
		RECEIVE_ONLY = 0,
		PUBLISH_ONLY = 1,
		DUPLEX = 2
	};
}