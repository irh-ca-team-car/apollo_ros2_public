#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_vehiclelimits24.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_vehiclelimits24.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusLlcVehiclelimits24 Llc_vehiclelimits_24;
}
#include "apollo_msgs/msg/apollocanbus_adc_motioncontrol110.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_adc_motioncontrol110.hpp"
#include "apollo_msgs/msg/apollocanbus_adc_motioncontrollimits112.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_adc_motioncontrollimits112.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAdcMotioncontrollimits112 Adc_motioncontrollimits1_12;
}
#include "apollo_msgs/msg/apollocanbus_llc_motionfeedback120.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_motionfeedback120.hpp"
#include "apollo_msgs/msg/apollocanbus_llc_motionfeedback221.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_motionfeedback221.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusLlcMotionfeedback221 Llc_motionfeedback2_21;
}
#include "apollo_msgs/msg/apollocanbus_llc_motioncommandfeedback122.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_motioncommandfeedback122.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusLlcMotioncommandfeedback122 Llc_motioncommandfeedback1_22;
}
#include "apollo_msgs/msg/apollocanbus_llc_vehiclestatus25.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_vehiclestatus25.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusLlcVehiclestatus25 Llc_vehiclestatus_25;
}
#include "apollo_msgs/msg/apollocanbus_llc_auxiliaryfeedback120.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_auxiliaryfeedback120.hpp"
#include "apollo_msgs/msg/apollocanbus_llc_diag_fault620.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_diag_fault620.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusLlcDiagFault620 Llc_diag_fault_620;
}
#include "apollo_msgs/msg/apollocanbus_llc_diag_steeringcontrol722.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_diag_steeringcontrol722.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusLlcDiagSteeringcontrol722 Llc_diag_steeringcontrol_722;
}
#include "apollo_msgs/msg/apollocanbus_adc_auxiliarycontrol110.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_adc_auxiliarycontrol110.hpp"
#include "apollo_msgs/msg/apollocanbus_llc_diag_brakecontrol721.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_diag_brakecontrol721.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusLlcDiagBrakecontrol721 Llc_diag_brakecontrol_721;
}
#include "apollo_msgs/msg/apollocanbus_transit.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_transit.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusTransit Transit;
}
namespace apollo::canbus::Adc_motioncontrol1_10{
	enum Adc_cmd_steeringcontrolmodeType {
		ADC_CMD_STEERINGCONTROLMODE_NONE = 0,
		ADC_CMD_STEERINGCONTROLMODE_ANGLE = 1,
		ADC_CMD_STEERINGCONTROLMODE_RESERVED_CURVATURE = 2,
		ADC_CMD_STEERINGCONTROLMODE_RESERVED = 3
	};
}
namespace apollo::canbus::Adc_motioncontrol1_10{
	enum Adc_cmd_gearType {
		ADC_CMD_GEAR_P_PARK = 0,
		ADC_CMD_GEAR_D_DRIVE = 1,
		ADC_CMD_GEAR_N_NEUTRAL = 2,
		ADC_CMD_GEAR_R_REVERSE = 3
	};
}
namespace apollo::canbus::Adc_motioncontrol1_10{
	enum Adc_cmd_autonomyrequestType {
		ADC_CMD_AUTONOMYREQUEST_AUTONOMY_NOT_REQUESTED = 0,
		ADC_CMD_AUTONOMYREQUEST_AUTONOMY_REQUESTED = 1,
		ADC_CMD_AUTONOMYREQUEST_RESERVED0 = 2,
		ADC_CMD_AUTONOMYREQUEST_RESERVED1 = 3
	};
}
namespace apollo::canbus::Adc_motioncontrol1_10{
	enum Adc_cmd_longitudinalcontrolmodeType {
		ADC_CMD_LONGITUDINALCONTROLMODE_NONE = 0,
		ADC_CMD_LONGITUDINALCONTROLMODE_RESERVED_VELOCITY_AND_ACCELERATION = 1,
		ADC_CMD_LONGITUDINALCONTROLMODE_RESERVED_FORCE = 2,
		ADC_CMD_LONGITUDINALCONTROLMODE_DIRECT_THROTTLE_BRAKE = 3
	};
}
namespace apollo::canbus::Llc_motionfeedback1_20{
	enum Llc_fbk_gearType {
		LLC_FBK_GEAR_P_PARK = 0,
		LLC_FBK_GEAR_D_DRIVE = 1,
		LLC_FBK_GEAR_N_NEUTRAL = 2,
		LLC_FBK_GEAR_R_REVERSE = 3
	};
}
namespace apollo::canbus::Llc_motionfeedback1_20{
	enum Llc_fbk_steeringcontrolmodeType {
		LLC_FBK_STEERINGCONTROLMODE_NONE = 0,
		LLC_FBK_STEERINGCONTROLMODE_ANGLE = 1,
		LLC_FBK_STEERINGCONTROLMODE_RESERVED_CURVATURE = 2,
		LLC_FBK_STEERINGCONTROLMODE_RESERVED = 3
	};
}
namespace apollo::canbus::Llc_motionfeedback1_20{
	enum Llc_fbk_longitudinalcontrolmodeType {
		LLC_FBK_LONGITUDINALCONTROLMODE_NONE = 0,
		LLC_FBK_LONGITUDINALCONTROLMODE_RESERVED_VELOCITY_AND_ACCELERATION = 1,
		LLC_FBK_LONGITUDINALCONTROLMODE_RESERVED_FORCE = 2,
		LLC_FBK_LONGITUDINALCONTROLMODE_DIRECT_THROTTLE_BRAKE = 3
	};
}
namespace apollo::canbus::Llc_motionfeedback1_20{
	enum Llc_fbk_stateType {
		LLC_FBK_STATE_RESERVED0 = 0,
		LLC_FBK_STATE_AUTONOMY_NOT_ALLOWED = 1,
		LLC_FBK_STATE_AUTONOMY_ALLOWED = 2,
		LLC_FBK_STATE_AUTONOMY_REQUESTED = 3,
		LLC_FBK_STATE_AUTONOMY = 4,
		LLC_FBK_STATE_RESERVED1 = 5,
		LLC_FBK_STATE_RESERVED2 = 6,
		LLC_FBK_STATE_RESERVED3 = 7,
		LLC_FBK_STATE_RESERVED4 = 8,
		LLC_FBK_STATE_RESERVED5 = 9,
		LLC_FBK_STATE_RESERVED6 = 10,
		LLC_FBK_STATE_RESERVED7 = 11,
		LLC_FBK_STATE_RESERVED8 = 12,
		LLC_FBK_STATE_DISENGAGE_REQUESTED = 13,
		LLC_FBK_STATE_DISENGAGED = 14,
		LLC_FBK_STATE_FAULT = 15
	};
}
namespace apollo::canbus::Llc_auxiliaryfeedback_120{
	enum Llc_fbk_turnsignalType {
		LLC_FBK_TURNSIGNAL_NONE = 0,
		LLC_FBK_TURNSIGNAL_LEFT = 1,
		LLC_FBK_TURNSIGNAL_RIGHT = 2,
		LLC_FBK_TURNSIGNAL_RESERVE = 3
	};
}
namespace apollo::canbus::Adc_auxiliarycontrol_110{
	enum Adc_cmd_turnsignalType {
		ADC_CMD_TURNSIGNAL_NONE = 0,
		ADC_CMD_TURNSIGNAL_LEFT = 1,
		ADC_CMD_TURNSIGNAL_RIGHT = 2,
		ADC_CMD_TURNSIGNAL_RESERVE = 3
	};
}