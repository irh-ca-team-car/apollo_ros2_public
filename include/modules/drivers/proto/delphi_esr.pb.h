#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodrivers_esr_status95e8.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status95e8.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversEsrStatus95e8 Esr_status9_5e8;
}
#include "apollo_msgs/msg/apollodrivers_esr_status65e5.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status65e5.hpp"
#include "apollo_msgs/msg/apollodrivers_esr_status55e4.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status55e4.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversEsrStatus55e4 Esr_status5_5e4;
}
#include "apollo_msgs/msg/apollodrivers_esr_status34e2.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status34e2.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversEsrStatus34e2 Esr_status3_4e2;
}
#include "apollo_msgs/msg/apollodrivers_esr_status44e3.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status44e3.hpp"
#include "apollo_msgs/msg/apollodrivers_motionpower.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_motionpower.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversMotionpower Motionpower;
}
#include "apollo_msgs/msg/apollodrivers_esr_trackmotionpower540.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_trackmotionpower540.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversEsrTrackmotionpower540 Esr_trackmotionpower_540;
}
#include "apollo_msgs/msg/apollodrivers_acm_inst_req7e0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_acm_inst_req7e0.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversAcmInstReq7e0 Acm_inst_req_7e0;
}
#include "apollo_msgs/msg/apollodrivers_esr_track01500.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_track01500.hpp"
#include "apollo_msgs/msg/apollodrivers_esr_valid15d0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_valid15d0.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversEsrValid15d0 Esr_valid1_5d0;
}
#include "apollo_msgs/msg/apollodrivers_esr_valid25d1.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_valid25d1.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversEsrValid25d1 Esr_valid2_5d1;
}
#include "apollo_msgs/msg/apollodrivers_acm_inst_resp7e4.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_acm_inst_resp7e4.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversAcmInstResp7e4 Acm_inst_resp_7e4;
}
#include "apollo_msgs/msg/apollodrivers_vehicle24f1.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle24f1.hpp"
#include "apollo_msgs/msg/apollodrivers_vehicle14f0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle14f0.hpp"
#include "apollo_msgs/msg/apollodrivers_esr_sim15c0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_sim15c0.hpp"
#include "apollo_msgs/msg/apollodrivers_esr_status14e0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status14e0.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversEsrStatus14e0 Esr_status1_4e0;
}
#include "apollo_msgs/msg/apollodrivers_esr_status24e1.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status24e1.hpp"
#include "apollo_msgs/msg/apollodrivers_esr_status85e7.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status85e7.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversEsrStatus85e7 Esr_status8_5e7;
}
#include "apollo_msgs/msg/apollodrivers_esr_status75e6.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status75e6.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversEsrStatus75e6 Esr_status7_5e6;
}
#include "apollo_msgs/msg/apollodrivers_vehicle35f2.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle35f2.hpp"
#include "apollo_msgs/msg/apollodrivers_vehicle45f3.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle45f3.hpp"
#include "apollo_msgs/msg/apollodrivers_vehicle55f4.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle55f4.hpp"
#include "apollo_msgs/msg/apollodrivers_vehicle65f5.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle65f5.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversVehicle65f5 Vehicle6_5f5;
}
#include "apollo_msgs/msg/apollodrivers_delphi_esr.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_delphi_esr.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversDelphiESR DelphiESR;
}
namespace apollo::drivers::Esr_status6_5e5{
	enum Can_tx_vertical_align_updatedType {
		CAN_TX_VERTICAL_ALIGN_UPDATED_NOT_UPDATED = 0,
		CAN_TX_VERTICAL_ALIGN_UPDATED_UPDATED = 1
	};
}
namespace apollo::drivers::Esr_status6_5e5{
	enum Can_tx_found_targetType {
		CAN_TX_FOUND_TARGET_NOT_FOUND = 0,
		CAN_TX_FOUND_TARGET_FOUND = 1
	};
}
namespace apollo::drivers::Esr_status6_5e5{
	enum Can_tx_factory_align_status_2Type {
		CAN_TX_FACTORY_ALIGN_STATUS_2_OFF = 0,
		CAN_TX_FACTORY_ALIGN_STATUS_2_BUSY = 1,
		CAN_TX_FACTORY_ALIGN_STATUS_2_SUCCESS = 2,
		CAN_TX_FACTORY_ALIGN_STATUS_2_FAIL_NO_TARGET = 3,
		CAN_TX_FACTORY_ALIGN_STATUS_2_FAIL_DEV_TOO_LARGE = 4,
		CAN_TX_FACTORY_ALIGN_STATUS_2_FAIL_VAR_TOO_LARGE = 5
	};
}
namespace apollo::drivers::Esr_status6_5e5{
	enum Can_tx_factory_align_status_1Type {
		CAN_TX_FACTORY_ALIGN_STATUS_1_OFF = 0,
		CAN_TX_FACTORY_ALIGN_STATUS_1_BUSY = 1,
		CAN_TX_FACTORY_ALIGN_STATUS_1_SUCCESS = 2,
		CAN_TX_FACTORY_ALIGN_STATUS_1_FAIL_NO_TARGET = 3,
		CAN_TX_FACTORY_ALIGN_STATUS_1_FAIL_DEV_TOO_LARGE = 4,
		CAN_TX_FACTORY_ALIGN_STATUS_1_FAIL_VAR_TOO_LARGE = 5
	};
}
namespace apollo::drivers::Esr_status6_5e5{
	enum Can_tx_recommend_unconvergeType {
		CAN_TX_RECOMMEND_UNCONVERGE_NOT_RECOMMEND = 0,
		CAN_TX_RECOMMEND_UNCONVERGE_RECOMMEND = 1
	};
}
namespace apollo::drivers::Esr_status6_5e5{
	enum Can_tx_system_power_modeType {
		CAN_TX_SYSTEM_POWER_MODE_DSP_INIT = 0,
		CAN_TX_SYSTEM_POWER_MODE_RADIATE_OFF = 1,
		CAN_TX_SYSTEM_POWER_MODE_RADIATE_ON = 2,
		CAN_TX_SYSTEM_POWER_MODE_DSP_SHUTDOWN = 3,
		CAN_TX_SYSTEM_POWER_MODE_DSP_OFF = 4,
		CAN_TX_SYSTEM_POWER_MODE_HOST_SHUTDOWN = 5,
		CAN_TX_SYSTEM_POWER_MODE_TEST = 6,
		CAN_TX_SYSTEM_POWER_MODE_7INVALID = 7
	};
}
namespace apollo::drivers::Esr_status4_4e3{
	enum Can_tx_truck_target_detType {
		CAN_TX_TRUCK_TARGET_DET_NOT_DETECTED = 0,
		CAN_TX_TRUCK_TARGET_DET_DETECTED = 1
	};
}
namespace apollo::drivers::Esr_status4_4e3{
	enum Can_tx_lr_only_grating_lobe_detType {
		CAN_TX_LR_ONLY_GRATING_LOBE_DET_NOT_DETECTED = 0,
		CAN_TX_LR_ONLY_GRATING_LOBE_DET_DETECTED = 1
	};
}
namespace apollo::drivers::Esr_status4_4e3{
	enum Can_tx_sidelobe_blockageType {
		CAN_TX_SIDELOBE_BLOCKAGE_OFF = 0,
		CAN_TX_SIDELOBE_BLOCKAGE_ON = 1
	};
}
namespace apollo::drivers::Esr_status4_4e3{
	enum Can_tx_partial_blockageType {
		CAN_TX_PARTIAL_BLOCKAGE_NOT_BLOCKED = 0,
		CAN_TX_PARTIAL_BLOCKAGE_BLOCKED = 1
	};
}
namespace apollo::drivers::Esr_status4_4e3{
	enum Can_tx_mr_lr_modeType {
		CAN_TX_MR_LR_MODE_RESERVED = 0,
		CAN_TX_MR_LR_MODE_OUTPUT_ONLY_MEDIUM_RANGE_TRACKS = 1,
		CAN_TX_MR_LR_MODE_OUTPUT_ONLY_LONG_RANGE_TRACKS = 2,
		CAN_TX_MR_LR_MODE_OUTPUT_ALL_MEDIUM_RANGE_AND_LONG = 3
	};
}
namespace apollo::drivers::Esr_track01_500{
	enum Can_tx_track_grouping_changedType {
		CAN_TX_TRACK_GROUPING_CHANGED_GROUPINGUNCHANGED = 0,
		CAN_TX_TRACK_GROUPING_CHANGED_GROUPINGCHANGED = 1
	};
}
namespace apollo::drivers::Esr_track01_500{
	enum Can_tx_track_oncomingType {
		CAN_TX_TRACK_ONCOMING_NOTONCOMING = 0,
		CAN_TX_TRACK_ONCOMING_ONCOMING = 1
	};
}
namespace apollo::drivers::Esr_track01_500{
	enum Can_tx_track_bridge_objectType {
		CAN_TX_TRACK_BRIDGE_OBJECT_NOT_BRIDGE = 0,
		CAN_TX_TRACK_BRIDGE_OBJECT_BRIDGE = 1
	};
}
namespace apollo::drivers::Esr_track01_500{
	enum Can_tx_track_statusType {
		CAN_TX_TRACK_STATUS_NO_TARGET = 0,
		CAN_TX_TRACK_STATUS_NEW_TARGET = 1,
		CAN_TX_TRACK_STATUS_NEW_UPDATED_TARGET = 2,
		CAN_TX_TRACK_STATUS_UPDATED_TARGET = 3,
		CAN_TX_TRACK_STATUS_COASTED_TARGET = 4,
		CAN_TX_TRACK_STATUS_MERGED_TARGET = 5,
		CAN_TX_TRACK_STATUS_INVALID_COASTED_TARGET = 6,
		CAN_TX_TRACK_STATUS_NEW_COASTED_TARGET = 7
	};
}
namespace apollo::drivers::Esr_track01_500{
	enum Can_tx_track_med_range_modeType {
		CAN_TX_TRACK_MED_RANGE_MODE_NO_MR_LR_UPDATE = 0,
		CAN_TX_TRACK_MED_RANGE_MODE_MR_UPDATE_ONLY = 1,
		CAN_TX_TRACK_MED_RANGE_MODE_LR_UPDATE_ONLY = 2,
		CAN_TX_TRACK_MED_RANGE_MODE_BOTH_MR_LR_UPDATE = 3
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_mr_only_transmitType {
		CAN_RX_MR_ONLY_TRANSMIT_OFF = 0,
		CAN_RX_MR_ONLY_TRANSMIT_ON = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_lr_only_transmitType {
		CAN_RX_LR_ONLY_TRANSMIT_OFF = 0,
		CAN_RX_LR_ONLY_TRANSMIT_ON = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_clear_faultsType {
		CAN_RX_CLEAR_FAULTS_OFF = 0,
		CAN_RX_CLEAR_FAULTS_ON = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_use_angle_misalignmentType {
		CAN_RX_USE_ANGLE_MISALIGNMENT_OFF = 0,
		CAN_RX_USE_ANGLE_MISALIGNMENT_ON = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_turn_signal_statusType {
		CAN_RX_TURN_SIGNAL_STATUS_OFF = 0,
		CAN_RX_TURN_SIGNAL_STATUS_LEFT = 1,
		CAN_RX_TURN_SIGNAL_STATUS_RIGHT = 2,
		CAN_RX_TURN_SIGNAL_STATUS_INVALID_3 = 3
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_blockage_disableType {
		CAN_RX_BLOCKAGE_DISABLE_ENABLED = 0,
		CAN_RX_BLOCKAGE_DISABLE_DISABLED = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_vehicle_speed_validityType {
		CAN_RX_VEHICLE_SPEED_VALIDITY_INVALID = 0,
		CAN_RX_VEHICLE_SPEED_VALIDITY_VALID = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_mmr_upside_downType {
		CAN_RX_MMR_UPSIDE_DOWN_RIGHT_SIDE_UP = 0,
		CAN_RX_MMR_UPSIDE_DOWN_UPSIDE_DOWN = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_wiper_statusType {
		CAN_RX_WIPER_STATUS_OFF = 0,
		CAN_RX_WIPER_STATUS_ON = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_raw_data_enableType {
		CAN_RX_RAW_DATA_ENABLE_FILTERED = 0,
		CAN_RX_RAW_DATA_ENABLE_RAW = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_radar_cmd_radiateType {
		CAN_RX_RADAR_CMD_RADIATE_OFF = 0,
		CAN_RX_RADAR_CMD_RADIATE_ON = 1
	};
}
namespace apollo::drivers::Vehicle2_4f1{
	enum Can_rx_grouping_modeType {
		CAN_RX_GROUPING_MODE_NO_GROUPING = 0,
		CAN_RX_GROUPING_MODE_GROUP_MOVING_ONLY = 1,
		CAN_RX_GROUPING_MODE_GROUP_STATIONARY_ONLY = 2,
		CAN_RX_GROUPING_MODE_GROUP_MOVING_STATIONARY = 3
	};
}
namespace apollo::drivers::Vehicle1_4f0{
	enum Can_rx_steering_angle_validityType {
		CAN_RX_STEERING_ANGLE_VALIDITY_INVALID = 0,
		CAN_RX_STEERING_ANGLE_VALIDITY_VALID = 1
	};
}
namespace apollo::drivers::Vehicle1_4f0{
	enum Can_rx_steering_angle_signType {
		CAN_RX_STEERING_ANGLE_SIGN_COUNTERCLOCKWISE = 0,
		CAN_RX_STEERING_ANGLE_SIGN_CLOCKWISE = 1
	};
}
namespace apollo::drivers::Vehicle1_4f0{
	enum Can_rx_steering_angle_rate_signType {
		CAN_RX_STEERING_ANGLE_RATE_SIGN_COUNTERCLOCKWISE = 0,
		CAN_RX_STEERING_ANGLE_RATE_SIGN_CLOCKWISE = 1
	};
}
namespace apollo::drivers::Vehicle1_4f0{
	enum Can_rx_yaw_rate_validityType {
		CAN_RX_YAW_RATE_VALIDITY_INVALID = 0,
		CAN_RX_YAW_RATE_VALIDITY_VALID = 1
	};
}
namespace apollo::drivers::Vehicle1_4f0{
	enum Can_rx_vehicle_speed_directionType {
		CAN_RX_VEHICLE_SPEED_DIRECTION_FORWARD = 0,
		CAN_RX_VEHICLE_SPEED_DIRECTION_REVERSE = 1
	};
}
namespace apollo::drivers::Esr_sim1_5c0{
	enum Can_rx_sim_track_idType {
		CAN_RX_SIM_TRACK_ID_NO_TARGET = 0,
		CAN_RX_SIM_TRACK_ID_TARGET_1 = 1,
		CAN_RX_SIM_TRACK_ID_TARGET_2 = 2
	};
}
namespace apollo::drivers::Esr_sim1_5c0{
	enum Can_rx_sim_statusType {
		CAN_RX_SIM_STATUS_INVALID = 0,
		CAN_RX_SIM_STATUS_NEW = 1,
		CAN_RX_SIM_STATUS_UPDATED = 2,
		CAN_RX_SIM_STATUS_COASTED = 3
	};
}
namespace apollo::drivers::Esr_sim1_5c0{
	enum Can_rx_sim_functionType {
		CAN_RX_SIM_FUNCTION_ACC = 0,
		CAN_RX_SIM_FUNCTION_RI = 1,
		CAN_RX_SIM_FUNCTION_FCW_MOVE = 2,
		CAN_RX_SIM_FUNCTION_FCW_STAT = 3,
		CAN_RX_SIM_FUNCTION_CMBB_MOVE = 4,
		CAN_RX_SIM_FUNCTION_CMBB_STAT = 5,
		CAN_RX_SIM_FUNCTION_ALL_MOVING_ACC_FCW_CMBB = 6,
		CAN_RX_SIM_FUNCTION_ALL_STAT_RI_FCW_CMBB = 7
	};
}
namespace apollo::drivers::Esr_status2_4e1{
	enum Can_tx_raw_data_modeType {
		CAN_TX_RAW_DATA_MODE_FILTERED = 0,
		CAN_TX_RAW_DATA_MODE_RAW = 1
	};
}
namespace apollo::drivers::Esr_status2_4e1{
	enum Can_tx_range_perf_errorType {
		CAN_TX_RANGE_PERF_ERROR_NOT_BLOCKED = 0,
		CAN_TX_RANGE_PERF_ERROR_BLOCKED = 1
	};
}
namespace apollo::drivers::Esr_status2_4e1{
	enum Can_tx_overheat_errorType {
		CAN_TX_OVERHEAT_ERROR_NOT_OVERTEMP = 0,
		CAN_TX_OVERHEAT_ERROR_OVERTEMP = 1
	};
}
namespace apollo::drivers::Esr_status2_4e1{
	enum Can_tx_internal_errorType {
		CAN_TX_INTERNAL_ERROR_NOT_FAILED = 0,
		CAN_TX_INTERNAL_ERROR_FAILED = 1
	};
}
namespace apollo::drivers::Esr_status2_4e1{
	enum Can_tx_grouping_modeType {
		CAN_TX_GROUPING_MODE_NO_GROUPING = 0,
		CAN_TX_GROUPING_MODE_GROUP_MOVING_ONLY = 1,
		CAN_TX_GROUPING_MODE_GROUP_STATIONARY_ONLY = 2,
		CAN_TX_GROUPING_MODE_GROUP_MOVING_STATIONARY = 3
	};
}
namespace apollo::drivers::Esr_status2_4e1{
	enum Can_tx_xcvr_operationalType {
		CAN_TX_XCVR_OPERATIONAL_OFF = 0,
		CAN_TX_XCVR_OPERATIONAL_ON = 1
	};
}
namespace apollo::drivers::Vehicle3_5f2{
	enum Can_rx_serv_align_typeType {
		CAN_RX_SERV_ALIGN_TYPE_AUTO_OR_DEALER = 0,
		CAN_RX_SERV_ALIGN_TYPE_VOLVO_SHORT_TRACK = 1
	};
}
namespace apollo::drivers::Vehicle3_5f2{
	enum Can_rx_serv_align_enableType {
		CAN_RX_SERV_ALIGN_ENABLE_DISABLED = 0,
		CAN_RX_SERV_ALIGN_ENABLE_ENABLED = 1
	};
}
namespace apollo::drivers::Vehicle3_5f2{
	enum Can_rx_auto_align_convergedType {
		CAN_RX_AUTO_ALIGN_CONVERGED_NOT_CONVERGED = 0,
		CAN_RX_AUTO_ALIGN_CONVERGED_CONVERGED = 1
	};
}
namespace apollo::drivers::Vehicle3_5f2{
	enum Can_rx_auto_align_disableType {
		CAN_RX_AUTO_ALIGN_DISABLE_ENABLED = 0,
		CAN_RX_AUTO_ALIGN_DISABLE_DISABLED = 1
	};
}
namespace apollo::drivers::Vehicle3_5f2{
	enum Can_rx_wheel_slipType {
		CAN_RX_WHEEL_SLIP_NO_CONTROL = 0,
		CAN_RX_WHEEL_SLIP_BRAKE_SLIP_CONTROL = 1,
		CAN_RX_WHEEL_SLIP_TRACTION_SLIP_CONTROL = 2,
		CAN_RX_WHEEL_SLIP_INVALID_3 = 3
	};
}
namespace apollo::drivers::Vehicle3_5f2{
	enum Can_rx_long_accel_validityType {
		CAN_RX_LONG_ACCEL_VALIDITY_INVALID = 0,
		CAN_RX_LONG_ACCEL_VALIDITY_VALID = 1
	};
}
namespace apollo::drivers::Vehicle3_5f2{
	enum Can_rx_lat_accel_validityType {
		CAN_RX_LAT_ACCEL_VALIDITY_INVALID = 0,
		CAN_RX_LAT_ACCEL_VALIDITY_VALID = 1
	};
}
namespace apollo::drivers::Vehicle4_5f3{
	enum Can_rx_fac_align_cmd_2Type {
		CAN_RX_FAC_ALIGN_CMD_2_OFF = 0,
		CAN_RX_FAC_ALIGN_CMD_2_ON = 1
	};
}
namespace apollo::drivers::Vehicle4_5f3{
	enum Can_rx_fac_align_cmd_1Type {
		CAN_RX_FAC_ALIGN_CMD_1_OFF = 0,
		CAN_RX_FAC_ALIGN_CMD_1_ON = 1
	};
}
namespace apollo::drivers::Vehicle5_5f4{
	enum Can_rx_yaw_rate_bias_shiftType {
		CAN_RX_YAW_RATE_BIAS_SHIFT_NO_DETECT = 0,
		CAN_RX_YAW_RATE_BIAS_SHIFT_DETECT = 1
	};
}