#include "modules/planning/proto/decision_name.pb.h"
#ifdef CASE
#undef CASE_BEGIN
#undef CASE
#undef CASE_END
#endif
#define CASE_BEGIN(val) \
	switch (val)        \
	{
#define CASE(X) \
	case X:     \
		return #X;
#define CASE_END(val) \
	}                 \
	return "?";

namespace apollo::planning
{
	std::string StopReasonCode_Name(StopReasonCode val)
	{
		CASE_BEGIN(val)
		CASE(STOP_REASON_HEAD_VEHICLE)
		CASE(STOP_REASON_DESTINATION)
		CASE(STOP_REASON_PEDESTRIAN)
		CASE(STOP_REASON_OBSTACLE)
		CASE(STOP_REASON_PREPARKING)
		CASE(STOP_REASON_SIGNAL) // only for red signal
		CASE(STOP_REASON_STOP_SIGN)
		CASE(STOP_REASON_YIELD_SIGN)
		CASE(STOP_REASON_CLEAR_ZONE)
		CASE(STOP_REASON_CROSSWALK)
		CASE(STOP_REASON_CREEPER)
		CASE(STOP_REASON_REFERENCE_END) // end of the reference_line
		CASE(STOP_REASON_YELLOW_SIGNAL) // yellow signal
		CASE(STOP_REASON_PULL_OVER)		// pull over
		CASE(STOP_REASON_SIDEPASS_SAFETY)
		CASE(STOP_REASON_PRE_OPEN_SPACE_STOP)
		CASE(STOP_REASON_LANE_CHANGE_URGENCY)
		CASE(STOP_REASON_EMERGENCY)
		CASE_END(val)
	}
}
namespace apollo::planning::ObjectNudge
{
	std::string Type_Name(Type val)
	{
		CASE_BEGIN(val)
		CASE(LEFT_NUDGE)		  // drive from the left side to nudge a static obstacle
		CASE(RIGHT_NUDGE)		  // drive from the right side to nudge a static obstacle
		CASE(DYNAMIC_LEFT_NUDGE)  // drive from the left side to nudge a dynamic obstacle
		CASE(DYNAMIC_RIGHT_NUDGE) // drive from the right side to nudge a dynamic obstacle
		CASE_END(val)
	}
}
namespace apollo::planning::ObjectSidePass
{
	std::string Type_Name(Type val)
	{
		CASE_BEGIN(val)
		CASE(LEFT)
		CASE(RIGHT)
		CASE_END(val)
	}
}
namespace apollo::planning::MainEmergencyStop
{
	std::string ReasonCode_Name(ReasonCode val)
	{
		CASE_BEGIN(val)
		CASE(ESTOP_REASON_INTERNAL_ERR )
		CASE(ESTOP_REASON_COLLISION )
		CASE(ESTOP_REASON_ST_FIND_PATH )
		CASE(ESTOP_REASON_ST_MAKE_DECISION )
		CASE(ESTOP_REASON_SENSOR_ERROR)
		CASE_END(val)
	}
}
namespace apollo::planning::MainChangeLane
{
	std::string Type_Name(Type val)
	{
		CASE_BEGIN(val)
		CASE(LEFT)
		CASE(RIGHT)
		CASE_END(val)
	}
}
namespace apollo::planning::MainParking
{
	std::string ParkingStatus_Name(ParkingStatus val)
	{
		CASE_BEGIN(val)
		CASE(IN_PARKING)
		CASE_END(val)
	}
}

#include "modules/planning/proto/decision_name.pb.h"