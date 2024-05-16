#pragma once
#include "apollo_msgs/msg/apollocanbus_aeb_systemstate11.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_systemstate11.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAebSystemstate11 Aeb_systemstate_11;
}
#include "apollo_msgs/msg/apollocanbus_vcu_vehicle_fault_response201.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_vehicle_fault_response201.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVcuVehicleFaultResponse201 Vcu_vehicle_fault_response_201;
}
#include "apollo_msgs/msg/apollocanbus_vcu_powerstatus214.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_powerstatus214.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVcuPowerstatus214 Vcu_powerstatus_214;
}
#include "apollo_msgs/msg/apollocanbus_ads_light_horn_command310.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_light_horn_command310.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAdsLightHornCommand310 Ads_light_horn_command_310;
}
#include "apollo_msgs/msg/apollocanbus_ads_brake_command46.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_brake_command46.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAdsBrakeCommand46 Ads_brake_command_46;
}
#include "apollo_msgs/msg/apollocanbus_vcu_brake_report47.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_brake_report47.hpp"
#include "apollo_msgs/msg/apollocanbus_vcu_eps_report57.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_eps_report57.hpp"
#include "apollo_msgs/msg/apollocanbus_ads_eps_command56.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_eps_command56.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAdsEpsCommand56 Ads_eps_command_56;
}
#include "apollo_msgs/msg/apollocanbus_ads_drive_command50.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_drive_command50.hpp"
#include "apollo_msgs/msg/apollocanbus_vcu_drive_report52.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_drive_report52.hpp"
#include "apollo_msgs/msg/apollocanbus_ads_diagnosis628.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_diagnosis628.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAdsDiagnosis628 Ads_diagnosis_628;
}
#include "apollo_msgs/msg/apollocanbus_vcu_nm401.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_nm401.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVcuNm401 Vcu_nm_401;
}
#include "apollo_msgs/msg/apollocanbus_vcu_vehicle_status_report101.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_vehicle_status_report101.hpp"
#include "apollo_msgs/msg/apollocanbus_vcu_vehicle_info_response502.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_vehicle_info_response502.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVcuVehicleInfoResponse502 Vcu_vehicle_info_response_502;
}
#include "apollo_msgs/msg/apollocanbus_aeb_diagnosis1626.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_diagnosis1626.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAebDiagnosis1626 Aeb_diagnosis1_626;
}
#include "apollo_msgs/msg/apollocanbus_aeb_diagresp718.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_diagresp718.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAebDiagresp718 Aeb_diagresp_718;
}
#include "apollo_msgs/msg/apollocanbus_pas1st_data311.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pas1st_data311.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusPas1stData311 Pas_1st_data_311;
}
#include "apollo_msgs/msg/apollocanbus_pas2nd_data312.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pas2nd_data312.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusPas2ndData312 Pas_2nd_data_312;
}
#include "apollo_msgs/msg/apollocanbus_aeb_wheelimpulse355.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_wheelimpulse355.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAebWheelimpulse355 Aeb_wheelimpulse_355;
}
#include "apollo_msgs/msg/apollocanbus_aeb_rearwheelspeed354.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_rearwheelspeed354.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAebRearwheelspeed354 Aeb_rearwheelspeed_354;
}
#include "apollo_msgs/msg/apollocanbus_aeb_frontwheelspeed353.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_frontwheelspeed353.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusAebFrontwheelspeed353 Aeb_frontwheelspeed_353;
}
#include "apollo_msgs/msg/apollocanbus_neolix_edu.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_neolix_edu.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusNeolixEdu Neolix_edu;
}
namespace apollo::canbus::Vcu_brake_report_47{
	enum Control_mode_respType {
		CONTROL_MODE_RESP_STANDBY = 0,
		CONTROL_MODE_RESP_AUTO_DRIVE = 1,
		CONTROL_MODE_RESP_NET_DRIVE = 2,
		CONTROL_MODE_RESP_REMOTE_CONTROL = 3,
		CONTROL_MODE_RESP_EMERGENCY_BRAKE = 4
	};
}
namespace apollo::canbus::Vcu_eps_report_57{
	enum Control_mode_respType {
		CONTROL_MODE_RESP_STANDBY = 0,
		CONTROL_MODE_RESP_AUTO_DRIVE = 1,
		CONTROL_MODE_RESP_NET_DRIVE = 2,
		CONTROL_MODE_RESP_REMOTE_CONTROL = 3,
		CONTROL_MODE_RESP_EMERGENCY_BRAKE = 4
	};
}
namespace apollo::canbus::Ads_drive_command_50{
	enum Auto_shift_commandType {
		AUTO_SHIFT_COMMAND_N = 0,
		AUTO_SHIFT_COMMAND_D = 1,
		AUTO_SHIFT_COMMAND_R = 2,
		AUTO_SHIFT_COMMAND_RESERVED = 3
	};
}
namespace apollo::canbus::Vcu_drive_report_52{
	enum Control_mode_respType {
		CONTROL_MODE_RESP_STANDBY = 0,
		CONTROL_MODE_RESP_AUTO_DRIVE = 1,
		CONTROL_MODE_RESP_NET_DRIVE = 2,
		CONTROL_MODE_RESP_REMOTE_CONTROL = 3,
		CONTROL_MODE_RESP_EMERGENCY_BRAKE = 4
	};
}
namespace apollo::canbus::Vcu_drive_report_52{
	enum Vcu_real_shiftType {
		VCU_REAL_SHIFT_N = 0,
		VCU_REAL_SHIFT_D = 1,
		VCU_REAL_SHIFT_R = 2,
		VCU_REAL_SHIFT_RESERVED = 3
	};
}
namespace apollo::canbus::Vcu_vehicle_status_report_101{
	enum Control_mode_respType {
		CONTROL_MODE_RESP_STANDBY = 0,
		CONTROL_MODE_RESP_AUTO_DRIVE = 1,
		CONTROL_MODE_RESP_NET_DRIVE = 2,
		CONTROL_MODE_RESP_REMOTE_CONTROL = 3,
		CONTROL_MODE_RESP_EMERGENCY_BRAKE = 4
	};
}