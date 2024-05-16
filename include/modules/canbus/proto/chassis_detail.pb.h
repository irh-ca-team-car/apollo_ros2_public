#pragma once
#include "modules/common/configs/proto/vehicle_config.pb.h"
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/canbus/proto/ch.pb.h"
#include "modules/canbus/proto/devkit.pb.h"
#include "modules/canbus/proto/ge3.pb.h"
#include "modules/canbus/proto/lexus.pb.h"
#include "modules/canbus/proto/transit.pb.h"
#include "modules/canbus/proto/wey.pb.h"
#include "modules/canbus/proto/zhongyun.pb.h"
#include "modules/canbus/proto/neolix_edu.pb.h"
#include "apollo_msgs/msg/apollocanbus_chassis_detail.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_chassis_detail.hpp"
#include "apollo_msgs/msg/apollocanbus_check_response_signal.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_check_response_signal.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusCheckResponseSignal CheckResponseSignal;
}
#include "apollo_msgs/msg/apollocanbus_battery.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_battery.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusBattery Battery;
}
#include "apollo_msgs/msg/apollocanbus_light.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_light.hpp"
#include "apollo_msgs/msg/apollocanbus_eps.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_eps.hpp"
#include "apollo_msgs/msg/apollocanbus_vehicle_spd.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_spd.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVehicleSpd VehicleSpd;
}
#include "apollo_msgs/msg/apollocanbus_deceleration.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_deceleration.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusDeceleration Deceleration;
}
#include "apollo_msgs/msg/apollocanbus_brake.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake.hpp"
#include "apollo_msgs/msg/apollocanbus_epb.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_epb.hpp"
#include "apollo_msgs/msg/apollocanbus_gas.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gas.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusGas Gas;
}
#include "apollo_msgs/msg/apollocanbus_esp.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_esp.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusEsp Esp;
}
#include "apollo_msgs/msg/apollocanbus_ems.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ems.hpp"
#include "apollo_msgs/msg/apollocanbus_gear.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusGear Gear;
}
#include "apollo_msgs/msg/apollocanbus_safety.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_safety.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusSafety Safety;
}
#include "apollo_msgs/msg/apollocanbus_basic_info.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_basic_info.hpp"
#include "apollo_msgs/msg/apollocanbus_global_rpt6a.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_global_rpt6a.hpp"
#include "apollo_msgs/msg/apollocanbus_brake_cmd6b.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_cmd6b.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusBrakeCmd6b Brake_cmd_6b;
}
#include "apollo_msgs/msg/apollocanbus_brake_rpt6c.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_rpt6c.hpp"
#include "apollo_msgs/msg/apollocanbus_steering_cmd6d.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_cmd6d.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusSteeringCmd6d Steering_cmd_6d;
}
#include "apollo_msgs/msg/apollocanbus_steering_rpt16e.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_rpt16e.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusSteeringRpt16e Steering_rpt_1_6e;
}
#include "apollo_msgs/msg/apollocanbus_wheel_speed_rpt7a.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wheel_speed_rpt7a.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusWheelSpeedRpt7a Wheel_speed_rpt_7a;
}
#include "apollo_msgs/msg/apollocanbus_date_time_rpt83.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_date_time_rpt83.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusDateTimeRpt83 Date_time_rpt_83;
}
#include "apollo_msgs/msg/apollocanbus_brake_motor_rpt170.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt170.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusBrakeMotorRpt170 Brake_motor_rpt_1_70;
}
#include "apollo_msgs/msg/apollocanbus_headlight_rpt77.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_headlight_rpt77.hpp"
#include "apollo_msgs/msg/apollocanbus_accel_rpt68.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_accel_rpt68.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAccelRpt68 Accel_rpt_68;
}
#include "apollo_msgs/msg/apollocanbus_steering_motor_rpt375.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt375.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusSteeringMotorRpt375 Steering_motor_rpt_3_75;
}
#include "apollo_msgs/msg/apollocanbus_turn_cmd63.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_turn_cmd63.hpp"
#include "apollo_msgs/msg/apollocanbus_turn_rpt64.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_turn_rpt64.hpp"
#include "apollo_msgs/msg/apollocanbus_shift_cmd65.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_shift_cmd65.hpp"
#include "apollo_msgs/msg/apollocanbus_shift_rpt66.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_shift_rpt66.hpp"
#include "apollo_msgs/msg/apollocanbus_accel_cmd67.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_accel_cmd67.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAccelCmd67 Accel_cmd_67;
}
#include "apollo_msgs/msg/apollocanbus_lat_lon_heading_rpt82.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_lat_lon_heading_rpt82.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusLatLonHeadingRpt82 Lat_lon_heading_rpt_82;
}
#include "apollo_msgs/msg/apollocanbus_global_cmd69.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_global_cmd69.hpp"
#include "apollo_msgs/msg/apollocanbus_parking_brake_status_rpt80.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_parking_brake_status_rpt80.hpp"
#include "apollo_msgs/msg/apollocanbus_yaw_rate_rpt81.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_yaw_rate_rpt81.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusYawRateRpt81 Yaw_rate_rpt_81;
}
#include "apollo_msgs/msg/apollocanbus_horn_rpt79.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_horn_rpt79.hpp"
#include "apollo_msgs/msg/apollocanbus_horn_cmd78.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_horn_cmd78.hpp"
#include "apollo_msgs/msg/apollocanbus_wiper_rpt91.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wiper_rpt91.hpp"
#include "apollo_msgs/msg/apollocanbus_vehicle_speed_rpt6f.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_speed_rpt6f.hpp"
#include "apollo_msgs/msg/apollocanbus_headlight_cmd76.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_headlight_cmd76.hpp"
#include "apollo_msgs/msg/apollocanbus_steering_motor_rpt274.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt274.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusSteeringMotorRpt274 Steering_motor_rpt_2_74;
}
#include "apollo_msgs/msg/apollocanbus_brake_motor_rpt271.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt271.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusBrakeMotorRpt271 Brake_motor_rpt_2_71;
}
#include "apollo_msgs/msg/apollocanbus_steering_motor_rpt173.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt173.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusSteeringMotorRpt173 Steering_motor_rpt_1_73;
}
#include "apollo_msgs/msg/apollocanbus_wiper_cmd90.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wiper_cmd90.hpp"
#include "apollo_msgs/msg/apollocanbus_brake_motor_rpt372.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt372.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusBrakeMotorRpt372 Brake_motor_rpt_3_72;
}
#include "apollo_msgs/msg/apollocanbus_gem.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gem.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusGem Gem;
}
namespace apollo::canbus::ChassisDetail{
	enum Type {
		QIRUI_EQ_15 = 0,
		CHANGAN_RUICHENG = 1
	};
}
namespace apollo::canbus::Light{
	enum TurnLightType {
		TURN_LIGHT_OFF = 0,
		TURN_LEFT_ON = 1,
		TURN_RIGHT_ON = 2,
		TURN_LIGHT_ON = 3
	};
}
namespace apollo::canbus::Light{
	enum BeamLampType {
		BEAM_OFF = 0,
		HIGH_BEAM_ON = 1,
		LOW_BEAM_ON = 2
	};
}
namespace apollo::canbus::Light{
	enum LincolnLampType {
		BEAM_NULL = 0,
		BEAM_FLASH_TO_PASS = 1,
		BEAM_HIGH = 2,
		BEAM_INVALID = 3
	};
}
namespace apollo::canbus::Light{
	enum LincolnWiperType {
		WIPER_OFF = 0,
		WIPER_AUTO_OFF = 1,
		WIPER_OFF_MOVING = 2,
		WIPER_MANUAL_OFF = 3,
		WIPER_MANUAL_ON = 4,
		WIPER_MANUAL_LOW = 5,
		WIPER_MANUAL_HIGH = 6,
		WIPER_MIST_FLICK = 7,
		WIPER_WASH = 8,
		WIPER_AUTO_LOW = 9,
		WIPER_AUTO_HIGH = 10,
		WIPER_COURTESY_WIPE = 11,
		WIPER_AUTO_ADJUST = 12,
		WIPER_RESERVED = 13,
		WIPER_STALLED = 14,
		WIPER_NO_DATA = 15
	};
}
namespace apollo::canbus::Light{
	enum LincolnAmbientType {
		AMBIENT_DARK = 0,
		AMBIENT_LIGHT = 1,
		AMBIENT_TWILIGHT = 2,
		AMBIENT_TUNNEL_ON = 3,
		AMBIENT_TUNNEL_OFF = 4,
		AMBIENT_INVALID = 5,
		AMBIENT_NO_DATA = 7
	};
}
namespace apollo::canbus::Eps{
	enum Type {
		NOT_AVAILABLE = 0,
		READY = 1,
		ACTIVE = 2,
		INVALID = 3
	};
}
namespace apollo::canbus::Brake{
	enum HSAStatusType {
		HSA_INACTIVE = 0,
		HSA_FINDING_GRADIENT = 1,
		HSA_ACTIVE_PRESSED = 2,
		HSA_ACTIVE_RELEASED = 3,
		HSA_FAST_RELEASE = 4,
		HSA_SLOW_RELEASE = 5,
		HSA_FAILED = 6,
		HSA_UNDEFINED = 7
	};
}
namespace apollo::canbus::Brake{
	enum HSAModeType {
		HSA_OFF = 0,
		HSA_AUTO = 1,
		HSA_MANUAL = 2,
		HSA_MODE_UNDEFINED = 3
	};
}
namespace apollo::canbus::Epb{
	enum PBrakeType {
		PBRAKE_OFF = 0,
		PBRAKE_TRANSITION = 1,
		PBRAKE_ON = 2,
		PBRAKE_FAULT = 3
	};
}
namespace apollo::canbus::Ems{
	enum Type {
		STOP = 0,
		CRANK = 1,
		RUNNING = 2,
		INVALID = 3
	};
}
namespace apollo::canbus::BasicInfo{
	enum Type {
		OFF = 0,
		ACC = 1,
		ON = 2,
		START = 3,
		INVALID = 4
	};
}
namespace apollo::canbus::Global_rpt_6a{
	enum Pacmod_statusType {
		PACMOD_STATUS_CONTROL_DISABLED = 0,
		PACMOD_STATUS_CONTROL_ENABLED = 1
	};
}
namespace apollo::canbus::Global_rpt_6a{
	enum Override_statusType {
		OVERRIDE_STATUS_NOT_OVERRIDDEN = 0,
		OVERRIDE_STATUS_OVERRIDDEN = 1
	};
}
namespace apollo::canbus::Global_rpt_6a{
	enum Brk_can_timeoutType {
		BRK_CAN_TIMEOUT_NO_ACTIVE_CAN_TIMEOUT = 0,
		BRK_CAN_TIMEOUT_ACTIVE_CAN_TIMEOUT = 1
	};
}
namespace apollo::canbus::Brake_rpt_6c{
	enum Brake_on_offType {
		BRAKE_ON_OFF_OFF = 0,
		BRAKE_ON_OFF_ON = 1
	};
}
namespace apollo::canbus::Headlight_rpt_77{
	enum Output_valueType {
		OUTPUT_VALUE_HEADLIGHTS_OFF = 0,
		OUTPUT_VALUE_LOW_BEAMS = 1,
		OUTPUT_VALUE_HIGH_BEAMS = 2
	};
}
namespace apollo::canbus::Headlight_rpt_77{
	enum Manual_inputType {
		MANUAL_INPUT_HEADLIGHTS_OFF = 0,
		MANUAL_INPUT_LOW_BEAMS = 1,
		MANUAL_INPUT_HIGH_BEAMS = 2
	};
}
namespace apollo::canbus::Headlight_rpt_77{
	enum Commanded_valueType {
		COMMANDED_VALUE_HEADLIGHTS_OFF = 0,
		COMMANDED_VALUE_LOW_BEAMS = 1,
		COMMANDED_VALUE_HIGH_BEAMS = 2
	};
}
namespace apollo::canbus::Turn_cmd_63{
	enum Turn_signal_cmdType {
		TURN_SIGNAL_CMD_RIGHT = 0,
		TURN_SIGNAL_CMD_NONE = 1,
		TURN_SIGNAL_CMD_LEFT = 2,
		TURN_SIGNAL_CMD_HAZARD = 3
	};
}
namespace apollo::canbus::Turn_rpt_64{
	enum Manual_inputType {
		MANUAL_INPUT_RIGHT = 0,
		MANUAL_INPUT_NONE = 1,
		MANUAL_INPUT_LEFT = 2,
		MANUAL_INPUT_HAZARD = 3
	};
}
namespace apollo::canbus::Turn_rpt_64{
	enum Commanded_valueType {
		COMMANDED_VALUE_RIGHT = 0,
		COMMANDED_VALUE_NONE = 1,
		COMMANDED_VALUE_LEFT = 2,
		COMMANDED_VALUE_HAZARD = 3
	};
}
namespace apollo::canbus::Turn_rpt_64{
	enum Output_valueType {
		OUTPUT_VALUE_RIGHT = 0,
		OUTPUT_VALUE_NONE = 1,
		OUTPUT_VALUE_LEFT = 2,
		OUTPUT_VALUE_HAZARD = 3
	};
}
namespace apollo::canbus::Shift_cmd_65{
	enum Shift_cmdType {
		SHIFT_CMD_PARK = 0,
		SHIFT_CMD_REVERSE = 1,
		SHIFT_CMD_NEUTRAL = 2,
		SHIFT_CMD_FORWARD = 3,
		SHIFT_CMD_LOW = 4
	};
}
namespace apollo::canbus::Shift_rpt_66{
	enum Manual_inputType {
		MANUAL_INPUT_PARK = 0,
		MANUAL_INPUT_REVERSE = 1,
		MANUAL_INPUT_NEUTRAL = 2,
		MANUAL_INPUT_FORWARD = 3,
		MANUAL_INPUT_HIGH = 4
	};
}
namespace apollo::canbus::Shift_rpt_66{
	enum Commanded_valueType {
		COMMANDED_VALUE_PARK = 0,
		COMMANDED_VALUE_REVERSE = 1,
		COMMANDED_VALUE_NEUTRAL = 2,
		COMMANDED_VALUE_FORWARD = 3,
		COMMANDED_VALUE_HIGH = 4
	};
}
namespace apollo::canbus::Shift_rpt_66{
	enum Output_valueType {
		OUTPUT_VALUE_PARK = 0,
		OUTPUT_VALUE_REVERSE = 1,
		OUTPUT_VALUE_NEUTRAL = 2,
		OUTPUT_VALUE_FORWARD = 3,
		OUTPUT_VALUE_HIGH = 4
	};
}
namespace apollo::canbus::Global_cmd_69{
	enum Pacmod_enableType {
		PACMOD_ENABLE_CONTROL_DISABLED = 0,
		PACMOD_ENABLE_CONTROL_ENABLED = 1
	};
}
namespace apollo::canbus::Global_cmd_69{
	enum Clear_overrideType {
		CLEAR_OVERRIDE_DON_T_CLEAR_ACTIVE_OVERRIDES = 0,
		CLEAR_OVERRIDE_CLEAR_ACTIVE_OVERRIDES = 1
	};
}
namespace apollo::canbus::Global_cmd_69{
	enum Ignore_overrideType {
		IGNORE_OVERRIDE_DON_T_IGNORE_USER_OVERRIDES = 0,
		IGNORE_OVERRIDE_IGNORE_USER_OVERRIDES = 1
	};
}
namespace apollo::canbus::Parking_brake_status_rpt_80{
	enum Parking_brake_enabledType {
		PARKING_BRAKE_ENABLED_OFF = 0,
		PARKING_BRAKE_ENABLED_ON = 1
	};
}
namespace apollo::canbus::Horn_rpt_79{
	enum Output_valueType {
		OUTPUT_VALUE_OFF = 0,
		OUTPUT_VALUE_ON = 1
	};
}
namespace apollo::canbus::Horn_rpt_79{
	enum Commanded_valueType {
		COMMANDED_VALUE_OFF = 0,
		COMMANDED_VALUE_ON = 1
	};
}
namespace apollo::canbus::Horn_rpt_79{
	enum Manual_inputType {
		MANUAL_INPUT_OFF = 0,
		MANUAL_INPUT_ON = 1
	};
}
namespace apollo::canbus::Horn_cmd_78{
	enum Horn_cmdType {
		HORN_CMD_OFF = 0,
		HORN_CMD_ON = 1
	};
}
namespace apollo::canbus::Wiper_rpt_91{
	enum Output_valueType {
		OUTPUT_VALUE_WIPERS_OFF = 0,
		OUTPUT_VALUE_INTERMITTENT_1 = 1,
		OUTPUT_VALUE_INTERMITTENT_2 = 2,
		OUTPUT_VALUE_INTERMITTENT_3 = 3,
		OUTPUT_VALUE_INTERMITTENT_4 = 4,
		OUTPUT_VALUE_INTERMITTENT_5 = 5,
		OUTPUT_VALUE_LOW = 6,
		OUTPUT_VALUE_HIGH = 7
	};
}
namespace apollo::canbus::Wiper_rpt_91{
	enum Commanded_valueType {
		COMMANDED_VALUE_WIPERS_OFF = 0,
		COMMANDED_VALUE_INTERMITTENT_1 = 1,
		COMMANDED_VALUE_INTERMITTENT_2 = 2,
		COMMANDED_VALUE_INTERMITTENT_3 = 3,
		COMMANDED_VALUE_INTERMITTENT_4 = 4,
		COMMANDED_VALUE_INTERMITTENT_5 = 5,
		COMMANDED_VALUE_LOW = 6,
		COMMANDED_VALUE_HIGH = 7
	};
}
namespace apollo::canbus::Wiper_rpt_91{
	enum Manual_inputType {
		MANUAL_INPUT_WIPERS_OFF = 0,
		MANUAL_INPUT_INTERMITTENT_1 = 1,
		MANUAL_INPUT_INTERMITTENT_2 = 2,
		MANUAL_INPUT_INTERMITTENT_3 = 3,
		MANUAL_INPUT_INTERMITTENT_4 = 4,
		MANUAL_INPUT_INTERMITTENT_5 = 5,
		MANUAL_INPUT_LOW = 6,
		MANUAL_INPUT_HIGH = 7
	};
}
namespace apollo::canbus::Vehicle_speed_rpt_6f{
	enum Vehicle_speed_validType {
		VEHICLE_SPEED_VALID_INVALID = 0,
		VEHICLE_SPEED_VALID_VALID = 1
	};
}
namespace apollo::canbus::Headlight_cmd_76{
	enum Headlight_cmdType {
		HEADLIGHT_CMD_HEADLIGHTS_OFF = 0,
		HEADLIGHT_CMD_LOW_BEAMS = 1,
		HEADLIGHT_CMD_HIGH_BEAMS = 2
	};
}
namespace apollo::canbus::Wiper_cmd_90{
	enum Wiper_cmdType {
		WIPER_CMD_WIPERS_OFF = 0,
		WIPER_CMD_INTERMITTENT_1 = 1,
		WIPER_CMD_INTERMITTENT_2 = 2,
		WIPER_CMD_INTERMITTENT_3 = 3,
		WIPER_CMD_INTERMITTENT_4 = 4,
		WIPER_CMD_INTERMITTENT_5 = 5,
		WIPER_CMD_LOW = 6,
		WIPER_CMD_HIGH = 7
	};
}