#pragma once
#include "apollo_msgs/msg/apollocanbus_pc_bcm201.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_bcm201.hpp"
#include "apollo_msgs/msg/apollocanbus_scu_bcs3308.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcs3308.hpp"
#include "apollo_msgs/msg/apollocanbus_pc_epb203.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_epb203.hpp"
#include "apollo_msgs/msg/apollocanbus_pc_bcs202.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_bcs202.hpp"
#include "apollo_msgs/msg/apollocanbus_pc_vcu205.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_vcu205.hpp"
#include "apollo_msgs/msg/apollocanbus_pc_eps204.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_eps204.hpp"
#include "apollo_msgs/msg/apollocanbus_scu_vcu2313.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_vcu2313.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusScuVcu2313 Scu_vcu_2_313;
}
#include "apollo_msgs/msg/apollocanbus_scu1301.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu1301.hpp"
#include "apollo_msgs/msg/apollocanbus_scu2302.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu2302.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusScu2302 Scu_2_302;
}
#include "apollo_msgs/msg/apollocanbus_scu3303.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu3303.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusScu3303 Scu_3_303;
}
#include "apollo_msgs/msg/apollocanbus_scu_bcm304.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcm304.hpp"
#include "apollo_msgs/msg/apollocanbus_scu_bcs1306.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcs1306.hpp"
#include "apollo_msgs/msg/apollocanbus_scu_bcs2307.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcs2307.hpp"
#include "apollo_msgs/msg/apollocanbus_scu_epb310.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_epb310.hpp"
#include "apollo_msgs/msg/apollocanbus_scu_vcu1312.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_vcu1312.hpp"
#include "apollo_msgs/msg/apollocanbus_scu_eps311.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_eps311.hpp"
#include "apollo_msgs/msg/apollocanbus_ge3.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ge3.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusGe3 Ge3;
}
namespace apollo::canbus::Pc_bcm_201{
	enum Pc_reverselampreqType {
		PC_REVERSELAMPREQ_NOREQ = 0,
		PC_REVERSELAMPREQ_REQ = 1
	};
}
namespace apollo::canbus::Pc_bcm_201{
	enum Pc_lowbeamreqType {
		PC_LOWBEAMREQ_NOREQ = 0,
		PC_LOWBEAMREQ_REQ = 1
	};
}
namespace apollo::canbus::Pc_bcm_201{
	enum Pc_highbeamreqType {
		PC_HIGHBEAMREQ_NOREQ = 0,
		PC_HIGHBEAMREQ_REQ = 1
	};
}
namespace apollo::canbus::Pc_bcm_201{
	enum Pc_rightturnlampreqType {
		PC_RIGHTTURNLAMPREQ_NOREQ = 0,
		PC_RIGHTTURNLAMPREQ_REQ = 1
	};
}
namespace apollo::canbus::Pc_bcm_201{
	enum Pc_leftturnlampreqType {
		PC_LEFTTURNLAMPREQ_NOREQ = 0,
		PC_LEFTTURNLAMPREQ_REQ = 1
	};
}
namespace apollo::canbus::Pc_bcm_201{
	enum Pc_hornreqType {
		PC_HORNREQ_NOREQ = 0,
		PC_HORNREQ_REQ = 1
	};
}
namespace apollo::canbus::Pc_bcm_201{
	enum Pc_hazardlampreqType {
		PC_HAZARDLAMPREQ_NOREQ = 0,
		PC_HAZARDLAMPREQ_REQ = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_rrwheelspdvdType {
		BCS_RRWHEELSPDVD_INVALID = 0,
		BCS_RRWHEELSPDVD_VALID = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_rrwheeldirectionvdType {
		BCS_RRWHEELDIRECTIONVD_INVALID = 0,
		BCS_RRWHEELDIRECTIONVD_VALID = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_rlwheelspdvdType {
		BCS_RLWHEELSPDVD_INVALID = 0,
		BCS_RLWHEELSPDVD_VALID = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_rlwheeldirectionvdType {
		BCS_RLWHEELDIRECTIONVD_INVALID = 0,
		BCS_RLWHEELDIRECTIONVD_VALID = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_frwheelspdvdType {
		BCS_FRWHEELSPDVD_INVALID = 0,
		BCS_FRWHEELSPDVD_VALID = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_frwheeldirectionvdType {
		BCS_FRWHEELDIRECTIONVD_INVALID = 0,
		BCS_FRWHEELDIRECTIONVD_VALID = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_flwheelspdvdType {
		BCS_FLWHEELSPDVD_INVALID = 0,
		BCS_FLWHEELSPDVD_VALID = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_flwheeldirectionvdType {
		BCS_FLWHEELDIRECTIONVD_INVALID = 0,
		BCS_FLWHEELDIRECTIONVD_VALID = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_rrwheeldirectionType {
		BCS_RRWHEELDIRECTION_FORWARD = 0,
		BCS_RRWHEELDIRECTION_BACKWARD = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_rlwheeldirectionType {
		BCS_RLWHEELDIRECTION_FORWARD = 0,
		BCS_RLWHEELDIRECTION_BACKWARD = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_frwheeldirectionType {
		BCS_FRWHEELDIRECTION_FORWARD = 0,
		BCS_FRWHEELDIRECTION_BACKWARD = 1
	};
}
namespace apollo::canbus::Scu_bcs_3_308{
	enum Bcs_flwheeldirectionType {
		BCS_FLWHEELDIRECTION_FORWARD = 0,
		BCS_FLWHEELDIRECTION_BACKWARD = 1
	};
}
namespace apollo::canbus::Pc_epb_203{
	enum Pc_epbreqType {
		PC_EPBREQ_INVALID = 0,
		PC_EPBREQ_RELEASE = 1,
		PC_EPBREQ_APPLY = 2
	};
}
namespace apollo::canbus::Pc_epb_203{
	enum Pc_epbenableType {
		PC_EPBENABLE_DISABLE = 0,
		PC_EPBENABLE_ENABLE = 1
	};
}
namespace apollo::canbus::Pc_bcs_202{
	enum Pc_brkpedenableType {
		PC_BRKPEDENABLE_DISABLE = 0,
		PC_BRKPEDENABLE_ENABLE = 1
	};
}
namespace apollo::canbus::Pc_vcu_205{
	enum Pc_accpedenableType {
		PC_ACCPEDENABLE_DISABLE = 0,
		PC_ACCPEDENABLE_ENABLE = 1
	};
}
namespace apollo::canbus::Pc_vcu_205{
	enum Pc_torqenableType {
		PC_TORQENABLE_DISABLE = 0,
		PC_TORQENABLE_ENABLE = 1
	};
}
namespace apollo::canbus::Pc_vcu_205{
	enum Pc_gearreqType {
		PC_GEARREQ_INVALID = 0,
		PC_GEARREQ_DRIVE = 1,
		PC_GEARREQ_NEUTRAL = 2,
		PC_GEARREQ_REVERSE = 3,
		PC_GEARREQ_PARK = 4
	};
}
namespace apollo::canbus::Pc_vcu_205{
	enum Pc_gearenableType {
		PC_GEARENABLE_DISABLE = 0,
		PC_GEARENABLE_ENABLE = 1
	};
}
namespace apollo::canbus::Pc_eps_204{
	enum Pc_steerenableType {
		PC_STEERENABLE_DISABLE = 0,
		PC_STEERENABLE_ENABLE = 1
	};
}
namespace apollo::canbus::Scu_1_301{
	enum Scu_stopbutstType {
		SCU_STOPBUTST_UNPRESSED = 0,
		SCU_STOPBUTST_PRESSED = 1
	};
}
namespace apollo::canbus::Scu_1_301{
	enum Scu_drvmodeType {
		SCU_DRVMODE_INVALID = 0,
		SCU_DRVMODE_MANUAL = 1,
		SCU_DRVMODE_INTERRUPT = 2,
		SCU_DRVMODE_AUTO = 3
	};
}
namespace apollo::canbus::Scu_1_301{
	enum Scu_faultstType {
		SCU_FAULTST_NORMAL = 0,
		SCU_FAULTST_FAULT = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_vehreversestType {
		BCM_VEHREVERSEST_NORMAL = 0,
		BCM_VEHREVERSEST_REVERSE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_rightturnlampstType {
		BCM_RIGHTTURNLAMPST_INACTIVE = 0,
		BCM_RIGHTTURNLAMPST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_rearfoglampstType {
		BCM_REARFOGLAMPST_INACTIVE = 0,
		BCM_REARFOGLAMPST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_parkinglampstType {
		BCM_PARKINGLAMPST_INACTIVE = 0,
		BCM_PARKINGLAMPST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_lowbeamstType {
		BCM_LOWBEAMST_INACTIVE = 0,
		BCM_LOWBEAMST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_leftturnlampstType {
		BCM_LEFTTURNLAMPST_INACTIVE = 0,
		BCM_LEFTTURNLAMPST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_keystType {
		BCM_KEYST_OFF = 0,
		BCM_KEYST_ACC = 1,
		BCM_KEYST_ON = 2,
		BCM_KEYST_CRANK = 3
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_hornstType {
		BCM_HORNST_INACTIVE = 0,
		BCM_HORNST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_highbeamstType {
		BCM_HIGHBEAMST_INACTIVE = 0,
		BCM_HIGHBEAMST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_hazardlampstType {
		BCM_HAZARDLAMPST_INACTIVE = 0,
		BCM_HAZARDLAMPST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_frontfoglampstType {
		BCM_FRONTFOGLAMPST_INACTIVE = 0,
		BCM_FRONTFOGLAMPST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcm_304{
	enum Bcm_brakelightswitchstType {
		BCM_BRAKELIGHTSWITCHST_INACTIVE = 0,
		BCM_BRAKELIGHTSWITCHST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcs_1_306{
	enum Bcs_aebavailableType {
		BCS_AEBAVAILABLE_UNAVAILABLE = 0,
		BCS_AEBAVAILABLE_AVAILABLE = 1
	};
}
namespace apollo::canbus::Scu_bcs_1_306{
	enum Bcs_cddavailableType {
		BCS_CDDAVAILABLE_UNAVAILABLE = 0,
		BCS_CDDAVAILABLE_AVAILABLE = 1
	};
}
namespace apollo::canbus::Scu_bcs_1_306{
	enum Bcs_intidxType {
		BCS_INTIDX_NOINT = 0,
		BCS_INTIDX_OVERFLOW = 1,
		BCS_INTIDX_TIMEOUT = 2,
		BCS_INTIDX_ACCPEDINT = 3,
		BCS_INTIDX_BRKPEDINT = 4,
		BCS_INTIDX_GEARINT = 5
	};
}
namespace apollo::canbus::Scu_bcs_1_306{
	enum Bcs_vdcfaultstType {
		BCS_VDCFAULTST_NORMAL = 0,
		BCS_VDCFAULTST_FAULT = 1
	};
}
namespace apollo::canbus::Scu_bcs_1_306{
	enum Bcs_vdcactivestType {
		BCS_VDCACTIVEST_INACTIVE = 0,
		BCS_VDCACTIVEST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcs_1_306{
	enum Bcs_absfaultstType {
		BCS_ABSFAULTST_NORMAL = 0,
		BCS_ABSFAULTST_FAULT = 1
	};
}
namespace apollo::canbus::Scu_bcs_1_306{
	enum Bcs_absactivestType {
		BCS_ABSACTIVEST_INACTIVE = 0,
		BCS_ABSACTIVEST_ACTIVE = 1
	};
}
namespace apollo::canbus::Scu_bcs_1_306{
	enum Bcs_faultstType {
		BCS_FAULTST_NORMAL = 0,
		BCS_FAULTST_FAULT = 1
	};
}
namespace apollo::canbus::Scu_bcs_1_306{
	enum Bcs_drvmodeType {
		BCS_DRVMODE_INVALID = 0,
		BCS_DRVMODE_MANUAL = 1,
		BCS_DRVMODE_INTERRUPT = 2,
		BCS_DRVMODE_AUTO = 3
	};
}
namespace apollo::canbus::Scu_bcs_2_307{
	enum Bcs_vehspdvdType {
		BCS_VEHSPDVD_INVALID = 0,
		BCS_VEHSPDVD_VALID = 1
	};
}
namespace apollo::canbus::Scu_epb_310{
	enum Epb_intidxType {
		EPB_INTIDX_NOINT = 0,
		EPB_INTIDX_OVERFLOW = 1,
		EPB_INTIDX_TIMEOUT = 2
	};
}
namespace apollo::canbus::Scu_epb_310{
	enum Epb_drvmodeType {
		EPB_DRVMODE_INVALID = 0,
		EPB_DRVMODE_MANUAL = 1,
		EPB_DRVMODE_INTERRUPT = 2,
		EPB_DRVMODE_AUTO = 3
	};
}
namespace apollo::canbus::Scu_epb_310{
	enum Epb_sysstType {
		EPB_SYSST_RELEASED = 0,
		EPB_SYSST_APPLIED = 1,
		EPB_SYSST_RELEASING = 2,
		EPB_SYSST_FAULT = 3,
		EPB_SYSST_APPLYING = 4,
		EPB_SYSST_DISENGAGED = 5
	};
}
namespace apollo::canbus::Scu_epb_310{
	enum Epb_faultstType {
		EPB_FAULTST_NORMAL = 0,
		EPB_FAULTST_FAULT = 1
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_elcsysfaultType {
		VCU_ELCSYSFAULT_NORMAL = 0,
		VCU_ELCSYSFAULT_FAULT = 1
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_brkpedstType {
		VCU_BRKPEDST_UNPRESSED = 0,
		VCU_BRKPEDST_PRESSED = 1
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_intidxType {
		VCU_INTIDX_NOINT = 0,
		VCU_INTIDX_OVERFLOW = 1,
		VCU_INTIDX_TIMEOUT = 2,
		VCU_INTIDX_ACCPEDINT = 3,
		VCU_INTIDX_BRKPEDINT = 4,
		VCU_INTIDX_GEARINT = 5
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_gearintidxType {
		VCU_GEARINTIDX_NOINT = 0,
		VCU_GEARINTIDX_OVERFLOW = 1,
		VCU_GEARINTIDX_TIMEOUT = 2
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_geardrvmodeType {
		VCU_GEARDRVMODE_INVALID = 0,
		VCU_GEARDRVMODE_MANUAL = 1,
		VCU_GEARDRVMODE_INTERRUPT = 2,
		VCU_GEARDRVMODE_AUTO = 3
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_vehrdystType {
		VCU_VEHRDYST_NOTREADY = 0,
		VCU_VEHRDYST_READY = 1
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_faultstType {
		VCU_FAULTST_NORMAL = 0,
		VCU_FAULTST_DERATE = 1,
		VCU_FAULTST_RSV1 = 2,
		VCU_FAULTST_RSV2 = 3,
		VCU_FAULTST_RSV3 = 4,
		VCU_FAULTST_FAULT = 5
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_drvmodeType {
		VCU_DRVMODE_INVALID = 0,
		VCU_DRVMODE_MANUAL = 1,
		VCU_DRVMODE_INTERRUPT = 2,
		VCU_DRVMODE_AUTO = 3
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_gearpstType {
		VCU_GEARPST_INVALID = 0,
		VCU_GEARPST_DRIVE = 1,
		VCU_GEARPST_NEUTRAL = 2,
		VCU_GEARPST_REVERSE = 3,
		VCU_GEARPST_PARK = 4
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_gearfaultstType {
		VCU_GEARFAULTST_NORMAL = 0,
		VCU_GEARFAULTST_FAULT = 1
	};
}
namespace apollo::canbus::Scu_vcu_1_312{
	enum Vcu_gearactType {
		VCU_GEARACT_INVALID = 0,
		VCU_GEARACT_DRIVE = 1,
		VCU_GEARACT_NEUTRAL = 2,
		VCU_GEARACT_REVERSE = 3,
		VCU_GEARACT_PARK = 4
	};
}
namespace apollo::canbus::Scu_eps_311{
	enum Eps_intidxType {
		EPS_INTIDX_NOINT = 0,
		EPS_INTIDX_OVERFLOW = 1,
		EPS_INTIDX_TIMEOUT = 2,
		EPS_INTIDX_STEERINT = 3
	};
}
namespace apollo::canbus::Scu_eps_311{
	enum Eps_faultstType {
		EPS_FAULTST_NORMAL = 0,
		EPS_FAULTST_FAULT = 1
	};
}
namespace apollo::canbus::Scu_eps_311{
	enum Eps_drvmodeType {
		EPS_DRVMODE_INVALID = 0,
		EPS_DRVMODE_MANUAL = 1,
		EPS_DRVMODE_INTERRUPT = 2,
		EPS_DRVMODE_AUTO = 3
	};
}