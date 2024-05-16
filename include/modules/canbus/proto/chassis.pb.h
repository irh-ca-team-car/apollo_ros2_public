#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/vehicle_signal.pb.h"
#include "modules/common/proto/drive_state.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/configs/proto/vehicle_config.pb.h"
#include "apollo_msgs/msg/apollocanbus_chassis.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_chassis.hpp"
#include "apollo_msgs/msg/apollocanbus_chassis_gps.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_chassis_gps.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusChassisGPS ChassisGPS;
}
#include "apollo_msgs/msg/apollocanbus_wheel_speed.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wheel_speed.hpp"
#include "apollo_msgs/msg/apollocanbus_sonar.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_sonar.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusSonar Sonar;
}
#include "apollo_msgs/msg/apollocanbus_surround.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_surround.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusSurround Surround;
}
#include "apollo_msgs/msg/apollocanbus_license.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_license.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusLicense License;
}
namespace apollo::canbus::Chassis{
	enum DrivingMode {
		COMPLETE_MANUAL = 0,  // human drive
		COMPLETE_AUTO_DRIVE = 1,
		AUTO_STEER_ONLY = 2,  // only steer
		AUTO_SPEED_ONLY = 3,  // include throttle and brake
		
		// security mode when manual intervention happens, only response status
		EMERGENCY_MODE = 4
	};
}
namespace apollo::canbus::Chassis{
	enum ErrorCode {
		NO_ERROR = 0,
		
		CMD_NOT_IN_PERIOD = 1,  // control cmd not in period
		
		// car chassis report error, like steer, brake, throttle, gear fault
		CHASSIS_ERROR = 2,
		
		// classify the types of the car chassis errors
		CHASSIS_ERROR_ON_STEER = 6,
		CHASSIS_ERROR_ON_BRAKE = 7,
		CHASSIS_ERROR_ON_THROTTLE = 8,
		CHASSIS_ERROR_ON_GEAR = 9,
		
		MANUAL_INTERVENTION = 3,  // human manual intervention
		
		// receive car chassis can frame not in period
		CHASSIS_CAN_NOT_IN_PERIOD = 4,
		
		UNKNOWN_ERROR = 5
	};
}
namespace apollo::canbus::Chassis{
	enum GearPosition {
		GEAR_NEUTRAL = 0,
		GEAR_DRIVE = 1,
		GEAR_REVERSE = 2,
		GEAR_PARKING = 3,
		GEAR_LOW = 4,
		GEAR_INVALID = 5,
		GEAR_NONE = 6
	};
}
namespace apollo::canbus{
	enum GpsQuality {
		FIX_NO = 0,
		FIX_2D = 1,
		FIX_3D = 2,
		FIX_INVALID = 3
	};
}
namespace apollo::canbus::WheelSpeed{
	enum WheelSpeedType {
		FORWARD = 0,
		BACKWARD = 1,
		STANDSTILL = 2,
		INVALID = 3
	};
}