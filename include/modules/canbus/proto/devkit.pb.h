#pragma once
#include "apollo_msgs/msg/apollocanbus_throttle_command100.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_command100.hpp"
#include "apollo_msgs/msg/apollocanbus_brake_command101.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_command101.hpp"
#include "apollo_msgs/msg/apollocanbus_steering_command102.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_command102.hpp"
#include "apollo_msgs/msg/apollocanbus_gear_command103.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_command103.hpp"
#include "apollo_msgs/msg/apollocanbus_park_command104.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_park_command104.hpp"
#include "apollo_msgs/msg/apollocanbus_throttle_report500.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_report500.hpp"
#include "apollo_msgs/msg/apollocanbus_brake_report501.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_report501.hpp"
#include "apollo_msgs/msg/apollocanbus_steering_report502.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_report502.hpp"
#include "apollo_msgs/msg/apollocanbus_gear_report503.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_report503.hpp"
#include "apollo_msgs/msg/apollocanbus_park_report504.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_park_report504.hpp"
#include "apollo_msgs/msg/apollocanbus_vcu_report505.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_report505.hpp"
#include "apollo_msgs/msg/apollocanbus_wheelspeed_report506.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wheelspeed_report506.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusWheelspeedReport506 Wheelspeed_report_506;
}
#include "apollo_msgs/msg/apollocanbus_ultr_sensor1507.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor1507.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusUltrSensor1507 Ultr_sensor_1_507;
}
#include "apollo_msgs/msg/apollocanbus_ultr_sensor2508.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor2508.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusUltrSensor2508 Ultr_sensor_2_508;
}
#include "apollo_msgs/msg/apollocanbus_ultr_sensor3509.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor3509.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusUltrSensor3509 Ultr_sensor_3_509;
}
#include "apollo_msgs/msg/apollocanbus_ultr_sensor4510.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor4510.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusUltrSensor4510 Ultr_sensor_4_510;
}
#include "apollo_msgs/msg/apollocanbus_ultr_sensor5511.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor5511.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusUltrSensor5511 Ultr_sensor_5_511;
}
#include "apollo_msgs/msg/apollocanbus_bms_report512.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_bms_report512.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusBmsReport512 Bms_report_512;
}
#include "apollo_msgs/msg/apollocanbus_devkit.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_devkit.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusDevkit Devkit;
}
namespace apollo::canbus::Throttle_command_100{
	enum Throttle_en_ctrlType {
		THROTTLE_EN_CTRL_DISABLE = 0,
		THROTTLE_EN_CTRL_ENABLE = 1
	};
}
namespace apollo::canbus::Brake_command_101{
	enum Aeb_en_ctrlType {
		AEB_EN_CTRL_DISABLE_AEB = 0,
		AEB_EN_CTRL_ENABLE_AEB = 1
	};
}
namespace apollo::canbus::Brake_command_101{
	enum Brake_en_ctrlType {
		BRAKE_EN_CTRL_DISABLE = 0,
		BRAKE_EN_CTRL_ENABLE = 1
	};
}
namespace apollo::canbus::Steering_command_102{
	enum Steer_en_ctrlType {
		STEER_EN_CTRL_DISABLE = 0,
		STEER_EN_CTRL_ENABLE = 1
	};
}
namespace apollo::canbus::Gear_command_103{
	enum Gear_targetType {
		GEAR_TARGET_INVALID = 0,
		GEAR_TARGET_PARK = 1,
		GEAR_TARGET_REVERSE = 2,
		GEAR_TARGET_NEUTRAL = 3,
		GEAR_TARGET_DRIVE = 4
	};
}
namespace apollo::canbus::Gear_command_103{
	enum Gear_en_ctrlType {
		GEAR_EN_CTRL_DISABLE = 0,
		GEAR_EN_CTRL_ENABLE = 1
	};
}
namespace apollo::canbus::Park_command_104{
	enum Park_targetType {
		PARK_TARGET_RELEASE = 0,
		PARK_TARGET_PARKING_TRIGGER = 1
	};
}
namespace apollo::canbus::Park_command_104{
	enum Park_en_ctrlType {
		PARK_EN_CTRL_DISABLE = 0,
		PARK_EN_CTRL_ENABLE = 1
	};
}
namespace apollo::canbus::Throttle_report_500{
	enum Throttle_flt2Type {
		THROTTLE_FLT2_NO_FAULT = 0,
		THROTTLE_FLT2_DRIVE_SYSTEM_COMUNICATION_FAULT = 1
	};
}
namespace apollo::canbus::Throttle_report_500{
	enum Throttle_flt1Type {
		THROTTLE_FLT1_NO_FAULT = 0,
		THROTTLE_FLT1_DRIVE_SYSTEM_HARDWARE_FAULT = 1
	};
}
namespace apollo::canbus::Throttle_report_500{
	enum Throttle_en_stateType {
		THROTTLE_EN_STATE_MANUAL = 0,
		THROTTLE_EN_STATE_AUTO = 1,
		THROTTLE_EN_STATE_TAKEOVER = 2,
		THROTTLE_EN_STATE_STANDBY = 3
	};
}
namespace apollo::canbus::Brake_report_501{
	enum Brake_flt2Type {
		BRAKE_FLT2_NO_FAULT = 0,
		BRAKE_FLT2_BRAKE_SYSTEM_COMUNICATION_FAULT = 1
	};
}
namespace apollo::canbus::Brake_report_501{
	enum Brake_flt1Type {
		BRAKE_FLT1_NO_FAULT = 0,
		BRAKE_FLT1_BRAKE_SYSTEM_HARDWARE_FAULT = 1
	};
}
namespace apollo::canbus::Brake_report_501{
	enum Brake_en_stateType {
		BRAKE_EN_STATE_MANUAL = 0,
		BRAKE_EN_STATE_AUTO = 1,
		BRAKE_EN_STATE_TAKEOVER = 2,
		BRAKE_EN_STATE_STANDBY = 3
	};
}
namespace apollo::canbus::Steering_report_502{
	enum Steer_flt2Type {
		STEER_FLT2_NO_FAULT = 0,
		STEER_FLT2_STEER_SYSTEM_COMUNICATION_FAULT = 1
	};
}
namespace apollo::canbus::Steering_report_502{
	enum Steer_flt1Type {
		STEER_FLT1_NO_FAULT = 0,
		STEER_FLT1_STEER_SYSTEM_HARDWARE_FAULT = 1
	};
}
namespace apollo::canbus::Steering_report_502{
	enum Steer_en_stateType {
		STEER_EN_STATE_MANUAL = 0,
		STEER_EN_STATE_AUTO = 1,
		STEER_EN_STATE_TAKEOVER = 2,
		STEER_EN_STATE_STANDBY = 3
	};
}
namespace apollo::canbus::Gear_report_503{
	enum Gear_fltType {
		GEAR_FLT_NO_FAULT = 0,
		GEAR_FLT_FAULT = 1
	};
}
namespace apollo::canbus::Gear_report_503{
	enum Gear_actualType {
		GEAR_ACTUAL_INVALID = 0,
		GEAR_ACTUAL_PARK = 1,
		GEAR_ACTUAL_REVERSE = 2,
		GEAR_ACTUAL_NEUTRAL = 3,
		GEAR_ACTUAL_DRIVE = 4
	};
}
namespace apollo::canbus::Park_report_504{
	enum Parking_actualType {
		PARKING_ACTUAL_RELEASE = 0,
		PARKING_ACTUAL_PARKING_TRIGGER = 1
	};
}
namespace apollo::canbus::Park_report_504{
	enum Park_fltType {
		PARK_FLT_NO_FAULT = 0,
		PARK_FLT_FAULT = 1
	};
}
namespace apollo::canbus::Vcu_report_505{
	enum Vehicle_mode_stateType {
		VEHICLE_MODE_STATE_MANUAL_REMOTE_MODE = 0,
		VEHICLE_MODE_STATE_AUTO_MODE = 1,
		VEHICLE_MODE_STATE_EMERGENCY_MODE = 2,
		VEHICLE_MODE_STATE_STANDBY_MODE = 3
	};
}
namespace apollo::canbus::Vcu_report_505{
	enum Frontcrash_stateType {
		FRONTCRASH_STATE_NO_EVENT = 0,
		FRONTCRASH_STATE_CRASH_EVENT = 1
	};
}
namespace apollo::canbus::Vcu_report_505{
	enum Backcrash_stateType {
		BACKCRASH_STATE_NO_EVENT = 0,
		BACKCRASH_STATE_CRASH_EVENT = 1
	};
}
namespace apollo::canbus::Vcu_report_505{
	enum Aeb_stateType {
		AEB_STATE_INACTIVE = 0,
		AEB_STATE_ACTIVE = 1
	};
}