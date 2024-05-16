#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollolocalization_integ_measure.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_integ_measure.hpp"
namespace apollo::localization::IntegMeasure{
	enum MeasureType {
		// the measure data only include gnss position
		GNSS_POS_ONLY = 0,
		// the measure data include gnss position and velocity
		GNSS_POS_VEL = 1,
		// the measure data include gnss position
		GNSS_POS_XY = 2,
		// the measure data only include gnss velocity
		GNSS_VEL_ONLY = 3,
		// the measure data only include point cloud position
		POINT_CLOUD_POS = 4,
		// the measure data only include odometer velocity
		ODOMETER_VEL_ONLY = 5,
		// trigger measure update using vehicle constraint
		VEHICLE_CONSTRAINT = 6
	};
}
namespace apollo::localization::IntegMeasure{
	enum FrameType {
		// Position give the longitude and latitude unit:rad.
		ENU = 0,
		// Position give x y and z from earth center.
		ECEF = 1,
		// Position give x y and z in utm frame.
		UTM = 2,
		ODOMETER = 3
	};
}