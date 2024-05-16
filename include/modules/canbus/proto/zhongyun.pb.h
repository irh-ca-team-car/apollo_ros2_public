#pragma once
#include "apollo_msgs/msg/apollocanbus_gear_control_a1.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_control_a1.hpp"
#include "apollo_msgs/msg/apollocanbus_torque_control_a3.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_torque_control_a3.hpp"
#include "apollo_msgs/msg/apollocanbus_steering_control_a2.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_control_a2.hpp"
#include "apollo_msgs/msg/apollocanbus_parking_control_a5.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_parking_control_a5.hpp"
#include "apollo_msgs/msg/apollocanbus_brake_control_a4.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_control_a4.hpp"
#include "apollo_msgs/msg/apollocanbus_enable_state_feedback_c3.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_enable_state_feedback_c3.hpp"
#include "apollo_msgs/msg/apollocanbus_vehicle_state_feedback_c1.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_state_feedback_c1.hpp"
#include "apollo_msgs/msg/apollocanbus_error_state_e1.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_error_state_e1.hpp"
#include "apollo_msgs/msg/apollocanbus_vehicle_state_feedback2_c4.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_state_feedback2_c4.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVehicleStateFeedback2C4 Vehicle_state_feedback_2_c4;
}
#include "apollo_msgs/msg/apollocanbus_zhongyun.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_zhongyun.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusZhongyun Zhongyun;
}
namespace apollo::canbus::Gear_control_a1{
	enum Gear_state_targetType {
		GEAR_STATE_TARGET_P = 1,
		GEAR_STATE_TARGET_N = 2,
		GEAR_STATE_TARGET_D = 3,
		GEAR_STATE_TARGET_R = 4,
		GEAR_STATE_TARGET_INVALID = 5
	};
}
namespace apollo::canbus::Gear_control_a1{
	enum Gear_enable_controlType {
		GEAR_ENABLE_CONTROL_GEAR_MANUALCONTROL = 0,
		GEAR_ENABLE_CONTROL_GEAR_AUTOCONTROL = 1
	};
}
namespace apollo::canbus::Torque_control_a3{
	enum Driven_enable_controlType {
		DRIVEN_ENABLE_CONTROL_DRIVE_MANUAL = 0,
		DRIVEN_ENABLE_CONTROL_DRIVE_AUTO = 1
	};
}
namespace apollo::canbus::Steering_control_a2{
	enum Steering_enable_controlType {
		STEERING_ENABLE_CONTROL_STEERING_MANUALCONTROL = 0,
		STEERING_ENABLE_CONTROL_STEERING_AUTOCONTROL = 1
	};
}
namespace apollo::canbus::Parking_control_a5{
	enum Parking_targetType {
		PARKING_TARGET_RELEASE = 0,
		PARKING_TARGET_PARKING_TRIGGER = 1
	};
}
namespace apollo::canbus::Parking_control_a5{
	enum Parking_enable_controlType {
		PARKING_ENABLE_CONTROL_PARKING_MANUALCONTROL = 0,
		PARKING_ENABLE_CONTROL_PARKING_AUTOCONTROL = 1
	};
}
namespace apollo::canbus::Brake_control_a4{
	enum Brake_enable_controlType {
		BRAKE_ENABLE_CONTROL_BRAKE_MANUAL = 0,
		BRAKE_ENABLE_CONTROL_BRAKE_AUTO = 1
	};
}
namespace apollo::canbus::Enable_state_feedback_c3{
	enum Parking_enable_stateType {
		PARKING_ENABLE_STATE_PARKING_MANUALCONTROL = 0,
		PARKING_ENABLE_STATE_PARKING_AUTOCONTROL = 1,
		PARKING_ENABLE_STATE_PARKING_TAKEOVER = 2
	};
}
namespace apollo::canbus::Enable_state_feedback_c3{
	enum Steering_enable_stateType {
		STEERING_ENABLE_STATE_STEERING_MANUALCONTROL = 0,
		STEERING_ENABLE_STATE_STEERING_AUTOCONTROL = 1,
		STEERING_ENABLE_STATE_STEERING_MANUAL_TAKEOVER = 2
	};
}
namespace apollo::canbus::Enable_state_feedback_c3{
	enum Gear_enable_actualType {
		GEAR_ENABLE_ACTUAL_GEAR_MANUALCONTROL = 0,
		GEAR_ENABLE_ACTUAL_GEAR_AUTOCONTROL = 1,
		GEAR_ENABLE_ACTUAL_GEAR_MANUAL_TAKEOVER = 2
	};
}
namespace apollo::canbus::Enable_state_feedback_c3{
	enum Driven_enable_stateType {
		DRIVEN_ENABLE_STATE_DRIVE_MANUAL = 0,
		DRIVEN_ENABLE_STATE_DRIVE_AUTO = 1,
		DRIVEN_ENABLE_STATE_DRIVE_TAKEOVER = 2
	};
}
namespace apollo::canbus::Enable_state_feedback_c3{
	enum Brake_enable_stateType {
		BRAKE_ENABLE_STATE_BRAKE_MANUAL = 0,
		BRAKE_ENABLE_STATE_BRAKE_AUTO = 1,
		BRAKE_ENABLE_STATE_BRAKE_TAKEOVER = 2
	};
}
namespace apollo::canbus::Vehicle_state_feedback_c1{
	enum Parking_actualType {
		PARKING_ACTUAL_RELEASE = 0,
		PARKING_ACTUAL_PARKING_TRIGGER = 1
	};
}
namespace apollo::canbus::Vehicle_state_feedback_c1{
	enum Gear_state_actualType {
		GEAR_STATE_ACTUAL_P = 1,
		GEAR_STATE_ACTUAL_N = 2,
		GEAR_STATE_ACTUAL_D = 3,
		GEAR_STATE_ACTUAL_R = 4,
		GEAR_STATE_ACTUAL_INVALID = 5
	};
}
namespace apollo::canbus::Error_state_e1{
	enum Brake_error_codeType {
		BRAKE_ERROR_CODE_NO_ERROR = 0,
		BRAKE_ERROR_CODE_ERROR = 1
	};
}
namespace apollo::canbus::Error_state_e1{
	enum Driven_error_codeType {
		DRIVEN_ERROR_CODE_NO_ERROR = 0,
		DRIVEN_ERROR_CODE_ERROR = 1
	};
}
namespace apollo::canbus::Error_state_e1{
	enum Steering_error_codeType {
		STEERING_ERROR_CODE_NO_ERROR = 0,
		STEERING_ERROR_CODE_ERROR = 1
	};
}
namespace apollo::canbus::Error_state_e1{
	enum Parking_error_codeType {
		PARKING_ERROR_CODE_NO_ERROR = 0,
		PARKING_ERROR_CODE_ERROR = 1
	};
}
namespace apollo::canbus::Error_state_e1{
	enum Gear_error_msgType {
		GEAR_ERROR_MSG_NO_ERROR = 0,
		GEAR_ERROR_MSG_ERROR = 1
	};
}