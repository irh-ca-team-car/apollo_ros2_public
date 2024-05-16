#pragma once
#include "apollo_msgs/msg/apollocanbus_throttle_command110.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_command110.hpp"
#include "apollo_msgs/msg/apollocanbus_brake_command111.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_command111.hpp"
#include "apollo_msgs/msg/apollocanbus_steer_command112.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steer_command112.hpp"
#include "apollo_msgs/msg/apollocanbus_turnsignal_command113.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_turnsignal_command113.hpp"
#include "apollo_msgs/msg/apollocanbus_gear_command114.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_command114.hpp"
#include "apollo_msgs/msg/apollocanbus_control_command115.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_control_command115.hpp"

#include "apollo_msgs/msg/apollocanbus_gear_status514.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_status514.hpp"
#include "apollo_msgs/msg/apollocanbus_ecu_status1515.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ecu_status1515.hpp"
#include "apollo_msgs/msg/apollocanbus_ecu_status2516.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ecu_status2516.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusEcuStatus2516 Ecu_status_2_516;
}
#include "apollo_msgs/msg/apollocanbus_ecu_status3517.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ecu_status3517.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusEcuStatus3517 Ecu_status_3_517;
}
#include "apollo_msgs/msg/apollocanbus_ch.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ch.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusCh Ch;
}
namespace apollo::canbus::Throttle_command_110{
	enum Throttle_pedal_en_ctrlType {
		THROTTLE_PEDAL_EN_CTRL_DISABLE = 0,
		THROTTLE_PEDAL_EN_CTRL_ENABLE = 1
	};
}
namespace apollo::canbus::Brake_command_111{
	enum Brake_pedal_en_ctrlType {
		BRAKE_PEDAL_EN_CTRL_DISABLE = 0,
		BRAKE_PEDAL_EN_CTRL_ENABLE = 1
	};
}
namespace apollo::canbus::Steer_command_112{
	enum Steer_angle_en_ctrlType {
		STEER_ANGLE_EN_CTRL_DISABLE = 0,
		STEER_ANGLE_EN_CTRL_ENABLE = 1
	};
}
namespace apollo::canbus::Turnsignal_command_113{
	enum Turn_signal_cmdType {
		TURN_SIGNAL_CMD_NONE = 0,
		TURN_SIGNAL_CMD_LEFT = 1,
		TURN_SIGNAL_CMD_RIGHT = 2
	};
}
namespace apollo::canbus::Gear_command_114{
	enum Gear_cmdType {
		GEAR_CMD_PARK = 1,
		GEAR_CMD_REVERSE = 2,
		GEAR_CMD_NEUTRAL = 3,
		GEAR_CMD_DRIVE = 4
	};
}
namespace apollo::canbus::Control_command_115{
	enum Ctrl_cmdType {
		CTRL_CMD_OUT_OF_CONTROL = 0,
		CTRL_CMD_UNDER_CONTROL = 1
	};
}
namespace apollo::canbus::Throttle_status__510{
	enum Throttle_pedal_en_stsType {
		THROTTLE_PEDAL_EN_STS_DISABLE = 0,
		THROTTLE_PEDAL_EN_STS_ENABLE = 1,
		THROTTLE_PEDAL_EN_STS_TAKEOVER = 2
	};
}
namespace apollo::canbus::Throttle_status__510{
	enum Drive_motor_errType {
		DRIVE_MOTOR_ERR_NOERR = 0,
		DRIVE_MOTOR_ERR_DRV_MOTOR_ERR = 1
	};
}
namespace apollo::canbus::Throttle_status__510{
	enum Battery_bms_errType {
		BATTERY_BMS_ERR_NOERR = 0,
		BATTERY_BMS_ERR_BATTERY_ERR = 1
	};
}
namespace apollo::canbus::Brake_status__511{
	enum Brake_pedal_en_stsType {
		BRAKE_PEDAL_EN_STS_DISABLE = 0,
		BRAKE_PEDAL_EN_STS_ENABLE = 1,
		BRAKE_PEDAL_EN_STS_TAKEOVER = 2
	};
}
namespace apollo::canbus::Brake_status__511{
	enum Brake_errType {
		BRAKE_ERR_NOERR = 0,
		BRAKE_ERR_BRAKE_SYSTEM_ERR = 1
	};
}
namespace apollo::canbus::Brake_status__511{
	enum Emergency_btn_envType {
		EMERGENCY_BTN_ENV_NOENV = 0,
		EMERGENCY_BTN_ENV_EMERGENCY_BUTTON_ENV = 1
	};
}
namespace apollo::canbus::Brake_status__511{
	enum Front_bump_envType {
		FRONT_BUMP_ENV_NOENV = 0,
		FRONT_BUMP_ENV_FRONT_BUMPER_ENV = 1
	};
}
namespace apollo::canbus::Brake_status__511{
	enum Back_bump_envType {
		BACK_BUMP_ENV_NOENV = 0,
		BACK_BUMP_ENV_BACK_BUMPER_ENV = 1
	};
}
namespace apollo::canbus::Brake_status__511{
	enum Overspd_envType {
		OVERSPD_ENV_NOENV = 0,
		OVERSPD_ENV_OVERSPEED_ENV = 1
	};
}
namespace apollo::canbus::Steer_status__512{
	enum Steer_angle_en_stsType {
		STEER_ANGLE_EN_STS_DISABLE = 0,
		STEER_ANGLE_EN_STS_ENABLE = 1,
		STEER_ANGLE_EN_STS_TAKEOVER = 2
	};
}
namespace apollo::canbus::Steer_status__512{
	enum Steer_errType {
		STEER_ERR_NOERR = 0,
		STEER_ERR_STEER_MOTOR_ERR = 1
	};
}
namespace apollo::canbus::Steer_status__512{
	enum Sensor_errType {
		SENSOR_ERR_NOERR = 0,
		SENSOR_ERR_STEER_SENSOR_ERR = 1
	};
}
namespace apollo::canbus::Turnsignal_status__513{
	enum Turn_signal_stsType {
		TURN_SIGNAL_STS_NONE = 0,
		TURN_SIGNAL_STS_LEFT = 1,
		TURN_SIGNAL_STS_RIGHT = 2
	};
}
namespace apollo::canbus::Gear_status_514{
	enum Gear_stsType {
		GEAR_STS_PARK = 1,
		GEAR_STS_REVERSE = 2,
		GEAR_STS_NEUTRAL = 3,
		GEAR_STS_DRIVE = 4
	};
}
namespace apollo::canbus::Ecu_status_1_515{
	enum Ctrl_stsType {
		CTRL_STS_OUT_OF_CONTROL = 0,
		CTRL_STS_UNDER_CONTROL = 1
	};
}