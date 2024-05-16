#pragma once
#include "modules/planning/proto/decision.pb.h"

namespace apollo::planning{
	std::string StopReasonCode_Name(StopReasonCode val);
}
namespace apollo::planning::ObjectNudge{
	std::string Type_Name(Type val);
}
namespace apollo::planning::ObjectSidePass{
	std::string Type_Name(Type val);
}
namespace apollo::planning::MainEmergencyStop{
	std::string ReasonCode_Name(ReasonCode val);
}
namespace apollo::planning::MainChangeLane{
	std::string Type_Name(Type val);
}
namespace apollo::planning::MainParking{
	std::string ParkingStatus_Name(ParkingStatus val);
	
}