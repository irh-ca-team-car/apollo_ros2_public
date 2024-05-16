#pragma once
#include "apollo_msgs/msg/apollocanbus_ads_shifter115.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_shifter115.hpp"
#include "apollo_msgs/msg/apollocanbus_ads_eps113.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_eps113.hpp"
#include "apollo_msgs/msg/apollocanbus_status310.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_status310.hpp"
#include "apollo_msgs/msg/apollocanbus_vin_resp3393.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vin_resp3393.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVinResp3393 Vin_resp3_393;
}
#include "apollo_msgs/msg/apollocanbus_vin_resp2392.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vin_resp2392.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVinResp2392 Vin_resp2_392;
}
#include "apollo_msgs/msg/apollocanbus_vin_resp1391.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vin_resp1391.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusVinResp1391 Vin_resp1_391;
}
#include "apollo_msgs/msg/apollocanbus_ads_req_vin390.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_req_vin390.hpp"
#include "apollo_msgs/msg/apollocanbus_ads1111.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads1111.hpp"
#include "apollo_msgs/msg/apollocanbus_fbs2240.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fbs2240.hpp"
#include "apollo_msgs/msg/apollocanbus_fbs1243.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fbs1243.hpp"
#include "apollo_msgs/msg/apollocanbus_fbs4235.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fbs4235.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusFbs4235 Fbs4_235;
}
#include "apollo_msgs/msg/apollocanbus_fail241.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fail241.hpp"
#include "apollo_msgs/msg/apollocanbus_fbs3237.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fbs3237.hpp"
#include "apollo_msgs/msg/apollocanbus_ads338e.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads338e.hpp"
#include "apollo_msgs/msg/apollocanbus_wey.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wey.hpp"
namespace apollo::canbus{
	typedef apollo_msgs::msg::ApollocanbusWey Wey;
}
namespace apollo::canbus::Ads_shifter_115{
	enum Ads_shiftmodeType {
		ADS_SHIFTMODE_INVALID = 0,
		ADS_SHIFTMODE_VALID = 1
	};
}
namespace apollo::canbus::Ads_shifter_115{
	enum Ads_targetgearType {
		ADS_TARGETGEAR_N = 0,
		ADS_TARGETGEAR_R = 1,
		ADS_TARGETGEAR_P = 2,
		ADS_TARGETGEAR_D = 3
	};
}
namespace apollo::canbus::Ads_eps_113{
	enum Ads_epsmodeType {
		ADS_EPSMODE_DISABLE = 0,
		ADS_EPSMODE_ACTIVE = 2
	};
}
namespace apollo::canbus::Status_310{
	enum LongitudeaccvalidType {
		LONGITUDEACCVALID_INVALID = 0,
		LONGITUDEACCVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum LateralaccevalidType {
		LATERALACCEVALID_INVALID = 0,
		LATERALACCEVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum VehdynyawratevalidType {
		VEHDYNYAWRATEVALID_INVALID = 0,
		VEHDYNYAWRATEVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum FlwheelspdvalidType {
		FLWHEELSPDVALID_INVALID = 0,
		FLWHEELSPDVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum FrwheelspdvalidType {
		FRWHEELSPDVALID_INVALID = 0,
		FRWHEELSPDVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum RlwheelspdvalidType {
		RLWHEELSPDVALID_INVALID = 0,
		RLWHEELSPDVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum RrwheelspdvalidType {
		RRWHEELSPDVALID_INVALID = 0,
		RRWHEELSPDVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum VehiclespdvalidType {
		VEHICLESPDVALID_INVALID = 0,
		VEHICLESPDVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum LongitudedrivingmodeType {
		LONGITUDEDRIVINGMODE_MANUALMODE = 0,
		LONGITUDEDRIVINGMODE_AUTOMATICSTANDBY = 1,
		LONGITUDEDRIVINGMODE_AUTOMATICACCELERATION = 2,
		LONGITUDEDRIVINGMODE_AUTOMATICDECELERATION = 3
	};
}
namespace apollo::canbus::Status_310{
	enum EngspdvalidType {
		ENGSPDVALID_INVALID = 0,
		ENGSPDVALID_VALID = 1,
		ENGSPDVALID_INIT_VALUE = 2,
		ENGSPDVALID_RESERVED = 3
	};
}
namespace apollo::canbus::Status_310{
	enum AccepedaloverrideType {
		ACCEPEDALOVERRIDE_NOT_OVERRIDE = 0,
		ACCEPEDALOVERRIDE_OVERRIDE = 1
	};
}
namespace apollo::canbus::Status_310{
	enum BrakepedalstatusType {
		BRAKEPEDALSTATUS_NOT_PRESSED = 0,
		BRAKEPEDALSTATUS_PRESSED = 1,
		BRAKEPEDALSTATUS_RESERVED1 = 2,
		BRAKEPEDALSTATUS_ERROR = 3
	};
}
namespace apollo::canbus::Status_310{
	enum EspbrakelightstsType {
		ESPBRAKELIGHTSTS_OFF = 0,
		ESPBRAKELIGHTSTS_ON = 1
	};
}
namespace apollo::canbus::Status_310{
	enum EpbswtpositionvalidType {
		EPBSWTPOSITIONVALID_VALID = 0,
		EPBSWTPOSITIONVALID_NOT_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum EpbstsType {
		EPBSTS_RELEASED = 0,
		EPBSTS_CLOSED = 1,
		EPBSTS_IN_PROGRESS = 2,
		EPBSTS_UNKNOWN = 3
	};
}
namespace apollo::canbus::Status_310{
	enum CurrentgearvalidType {
		CURRENTGEARVALID_INVALID = 0,
		CURRENTGEARVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum EpstrqsnsrstsType {
		EPSTRQSNSRSTS_NORMAL = 0,
		EPSTRQSNSRSTS_ABNORMAL = 1
	};
}
namespace apollo::canbus::Status_310{
	enum Eps_interferdetdvalidType {
		EPS_INTERFERDETDVALID_INVALID = 0,
		EPS_INTERFERDETDVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum EpshandsdetnstsType {
		EPSHANDSDETNSTS_HANDSOFF_NOT_DETECTED = 0,
		EPSHANDSDETNSTS_HANDOFFF_DETECTED = 1
	};
}
namespace apollo::canbus::Status_310{
	enum Eps_handsdetnstsvalidType {
		EPS_HANDSDETNSTSVALID_INVALID = 0,
		EPS_HANDSDETNSTSVALID_VALID = 1
	};
}
namespace apollo::canbus::Status_310{
	enum SteerwheelanglesignType {
		STEERWHEELANGLESIGN_LEFT_POSITIVE = 0,
		STEERWHEELANGLESIGN_RIGHT_NEGATIVE = 1
	};
}
namespace apollo::canbus::Status_310{
	enum SteerwheelspdsignType {
		STEERWHEELSPDSIGN_LEFT_POSITIVE = 0,
		STEERWHEELSPDSIGN_RIGHT_NEGATIVE = 1
	};
}
namespace apollo::canbus::Status_310{
	enum DriverdoorstsType {
		DRIVERDOORSTS_CLOSED = 0,
		DRIVERDOORSTS_OPEN = 1
	};
}
namespace apollo::canbus::Status_310{
	enum RldoorstsType {
		RLDOORSTS_CLOSED = 0,
		RLDOORSTS_OPEN = 1
	};
}
namespace apollo::canbus::Status_310{
	enum PassengerdoorstsType {
		PASSENGERDOORSTS_CLOSED = 0,
		PASSENGERDOORSTS_OPEN = 1
	};
}
namespace apollo::canbus::Status_310{
	enum RrdoorstsType {
		RRDOORSTS_CLOSED = 0,
		RRDOORSTS_OPEN = 1
	};
}
namespace apollo::canbus::Status_310{
	enum FrontfoglmpstsType {
		FRONTFOGLMPSTS_OFF = 0,
		FRONTFOGLMPSTS_ON = 1,
		FRONTFOGLMPSTS_RESERVED = 2,
		FRONTFOGLMPSTS_NOT_AVAILABLE = 3
	};
}
namespace apollo::canbus::Status_310{
	enum RearfoglmpstsType {
		REARFOGLMPSTS_OFF = 0,
		REARFOGLMPSTS_ON = 1
	};
}
namespace apollo::canbus::Status_310{
	enum LowbeamstsType {
		LOWBEAMSTS_OFF = 0,
		LOWBEAMSTS_ON = 1
	};
}
namespace apollo::canbus::Status_310{
	enum HighbeamstsType {
		HIGHBEAMSTS_OFF = 0,
		HIGHBEAMSTS_ON = 1
	};
}
namespace apollo::canbus::Status_310{
	enum LeftturnlampstsType {
		LEFTTURNLAMPSTS_OFF = 0,
		LEFTTURNLAMPSTS_ON = 1
	};
}
namespace apollo::canbus::Status_310{
	enum RightturnlampstsType {
		RIGHTTURNLAMPSTS_OFF = 0,
		RIGHTTURNLAMPSTS_ON = 1
	};
}
namespace apollo::canbus::Status_310{
	enum Bcm_availstsType {
		BCM_AVAILSTS_MANUAL_MODE = 0,
		BCM_AVAILSTS_AUTONOMOUS_MODE = 1,
		BCM_AVAILSTS_RESERVED1 = 2,
		BCM_AVAILSTS_RESERVED2 = 3
	};
}
namespace apollo::canbus::Status_310{
	enum BrakelmpstsType {
		BRAKELMPSTS_OFF = 0,
		BRAKELMPSTS_ON = 1
	};
}
namespace apollo::canbus::Ads_req_vin_390{
	enum Req_vin_signalType {
		REQ_VIN_SIGNAL_NO_REQUEST = 0,
		REQ_VIN_SIGNAL_REQUEST = 1
	};
}
namespace apollo::canbus::Ads1_111{
	enum Ads_dectostopType {
		ADS_DECTOSTOP_NO_DEMAND = 0,
		ADS_DECTOSTOP_DEMAND = 1
	};
}
namespace apollo::canbus::Ads1_111{
	enum Ads_modeType {
		ADS_MODE_OFF_MODE = 0,
		ADS_MODE_ACTIVE_MODE = 3
	};
}
namespace apollo::canbus::Ads1_111{
	enum Ads_driveoff_reqType {
		ADS_DRIVEOFF_REQ_NO_DEMAND = 0,
		ADS_DRIVEOFF_REQ_DEMAND = 1
	};
}
namespace apollo::canbus::Ads1_111{
	enum Ads_aeb_tgtdecel_reqType {
		ADS_AEB_TGTDECEL_REQ_NO_DEMAND = 0,
		ADS_AEB_TGTDECEL_REQ_DEMAND = 1
	};
}
namespace apollo::canbus::Fbs2_240{
	enum FlwheeldirectionType {
		FLWHEELDIRECTION_INVALID = 0,
		FLWHEELDIRECTION_FORWARD = 1,
		FLWHEELDIRECTION_BACKWARD = 2,
		FLWHEELDIRECTION_STOP = 3
	};
}
namespace apollo::canbus::Fbs2_240{
	enum RlwheeldrivedirectionType {
		RLWHEELDRIVEDIRECTION_INVALID = 0,
		RLWHEELDRIVEDIRECTION_FORWARD = 1,
		RLWHEELDRIVEDIRECTION_BACKWARD = 2,
		RLWHEELDRIVEDIRECTION_STOP = 3
	};
}
namespace apollo::canbus::Fbs2_240{
	enum RrwheeldirectionType {
		RRWHEELDIRECTION_INVALID = 0,
		RRWHEELDIRECTION_FORWARD = 1,
		RRWHEELDIRECTION_BACKWARD = 2,
		RRWHEELDIRECTION_STOP = 3
	};
}
namespace apollo::canbus::Fbs1_243{
	enum FrwheeldirectionType {
		FRWHEELDIRECTION_INVALID = 0,
		FRWHEELDIRECTION_FORWARD = 1,
		FRWHEELDIRECTION_BACKWARD = 2,
		FRWHEELDIRECTION_STOP = 3
	};
}
namespace apollo::canbus::Fail_241{
	enum EngfailType {
		ENGFAIL_NO_FAIL = 0,
		ENGFAIL_FAIL = 1
	};
}
namespace apollo::canbus::Fail_241{
	enum EspfailType {
		ESPFAIL_NO_FAILURE = 0,
		ESPFAIL_FAILURE = 1
	};
}
namespace apollo::canbus::Fail_241{
	enum EpbfailType {
		EPBFAIL_UNDEFINED = 0,
		EPBFAIL_NO_ERROR = 1,
		EPBFAIL_ERROR = 2,
		EPBFAIL_DIAGNOSIS = 3
	};
}
namespace apollo::canbus::Fail_241{
	enum ShiftfailType {
		SHIFTFAIL_NO_FAIL = 0,
		SHIFTFAIL_TRANSMISSION_MALFUNCTION = 1,
		SHIFTFAIL_TRANSMISSION_P_ENGAGEMENT_FAULT = 2,
		SHIFTFAIL_TRANSMISSION_P_DISENGAGEMENT_FAULT = 3,
		SHIFTFAIL_RESERVED = 4,
		SHIFTFAIL_TRANSMISSION_LIMIT_FUNCTION = 15
	};
}
namespace apollo::canbus::Fail_241{
	enum EpsfailType {
		EPSFAIL_NO_FAULT = 0,
		EPSFAIL_FAULT = 1
	};
}
namespace apollo::canbus::Fbs3_237{
	enum EpbswtichpositionType {
		EPBSWTICHPOSITION_NEUTRAL = 0,
		EPBSWTICHPOSITION_RELEASE = 1,
		EPBSWTICHPOSITION_APPLY = 2,
		EPBSWTICHPOSITION_RESERVED1 = 3
	};
}
namespace apollo::canbus::Fbs3_237{
	enum CurrentgearType {
		CURRENTGEAR_P = 0,
		CURRENTGEAR_R = 1,
		CURRENTGEAR_N = 2,
		CURRENTGEAR_D = 3
	};
}
namespace apollo::canbus::Fbs3_237{
	enum Eps_streeingmodeType {
		EPS_STREEINGMODE_MANUAL = 0,
		EPS_STREEINGMODE_AUTOMATIC_AVAIL = 1,
		EPS_STREEINGMODE_MANUAL_FROM_DRVNTERFERENCE = 2,
		EPS_STREEINGMODE_MANUAL_FROM_EPS_FAILED_DETECTED = 3,
		EPS_STREEINGMODE_TEMPORARY_INHIBITED = 4,
		EPS_STREEINGMODE_RESERVED1 = 5,
		EPS_STREEINGMODE_RESERVED2 = 6,
		EPS_STREEINGMODE_RESERVED3 = 7
	};
}
namespace apollo::canbus::Fbs3_237{
	enum EpscurrmodType {
		EPSCURRMOD_NORMAL_MODE = 0,
		EPSCURRMOD_SPORT_MODE = 1,
		EPSCURRMOD_COMFORT_MODE = 2,
		EPSCURRMOD_MODESELECTIONNOTPOSSIBLE = 3,
		EPSCURRMOD_NO_DISPLAY = 4,
		EPSCURRMOD_CONDITIONNOTMEET = 5,
		EPSCURRMOD_RESERVED1 = 6
	};
}
namespace apollo::canbus::Ads3_38e{
	enum Ads_bcm_workstsType {
		ADS_BCM_WORKSTS_DISABLE = 0,
		ADS_BCM_WORKSTS_ENABLE = 1,
		ADS_BCM_WORKSTS_ACTIVE = 2,
		ADS_BCM_WORKSTS_FAILED = 3
	};
}
namespace apollo::canbus::Ads3_38e{
	enum Ads_bcmworkstsvalidType {
		ADS_BCMWORKSTSVALID_INVALID = 0,
		ADS_BCMWORKSTSVALID_VALID = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum Ads_reqcontrolbcmType {
		ADS_REQCONTROLBCM_NO_REQUEST = 0,
		ADS_REQCONTROLBCM_REQUEST = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum HighbeamtonType {
		HIGHBEAMTON_TURN_OFF = 0,
		HIGHBEAMTON_TURN_ON = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum DippedbeamonType {
		DIPPEDBEAMON_TURN_OFF = 0,
		DIPPEDBEAMON_TURN_ON = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum TurnllightonType {
		TURNLLIGHTON_TURN_OFF = 0,
		TURNLLIGHTON_TURN_LEFT_ON = 1,
		TURNLLIGHTON_TURN_RIGHT_ON = 2,
		TURNLLIGHTON_RESERVED = 3
	};
}
namespace apollo::canbus::Ads3_38e{
	enum EmergencylightonType {
		EMERGENCYLIGHTON_TURN_OFF = 0,
		EMERGENCYLIGHTON_TURN_ON = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum FfoglamponType {
		FFOGLAMPON_TURN_OFF = 0,
		FFOGLAMPON_TURN_ON = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum RfoglamponType {
		RFOGLAMPON_TURN_OFF = 0,
		RFOGLAMPON_TURN_ON = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum BrakelightType {
		BRAKELIGHT_TURN_OFF = 0,
		BRAKELIGHT_TURN_ON = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum HornonType {
		HORNON_TURN_OFF = 0,
		HORNON_TURN_ON = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum FwindshieldwiperType {
		FWINDSHIELDWIPER_TURN_OFF = 0,
		FWINDSHIELDWIPER_TURN_ON = 1
	};
}
namespace apollo::canbus::Ads3_38e{
	enum RwindshieldwiperType {
		RWINDSHIELDWIPER_TURN_OFF = 0,
		RWINDSHIELDWIPER_TURN_ON = 1
	};
}