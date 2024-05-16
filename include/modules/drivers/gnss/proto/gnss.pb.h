#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollodriversgnss_gnss.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_gnss.hpp"
#include "apollo_msgs/msg/apollodriversgnss_raw_data.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_raw_data.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssRawData RawData;
}
namespace apollo::drivers::gnss::Gnss{
	enum Type {
		// It is recommended not using the GNSS solution if solution type is INVALID
		// or PROPAGATED.
		INVALID = 0,     // Invalid solution due to insufficient observations,
		// integrity warning, etc.
		PROPAGATED = 1,  // Propagated by a Kalman filter without new observations.
		
		// It is recommended using the following types of solution.
		SINGLE = 2,       // Standard GNSS solution without any corrections.
		PSRDIFF = 3,      // Pseudorange differential solution, including WAAS/SBAS
		// solution.
		PPP = 4,          // Precise Point Positioning (PPP) solution.
		RTK_FLOAT = 5,    // Real Time Kinematic (RTK) float solution.
		RTK_INTEGER = 6  // RTK integer solution.
	};
}