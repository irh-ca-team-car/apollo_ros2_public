#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodriversgnss_gnss_best_pose.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_gnss_best_pose.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssGnssBestPose GnssBestPose;
}
namespace apollo::drivers::gnss{
	enum SolutionStatus {
		SOL_COMPUTED = 0,      // solution computed
		INSUFFICIENT_OBS = 1,  // insufficient observations
		NO_CONVERGENCE = 2,    // no convergence
		SINGULARITY = 3,       // singularity at parameters matrix
		COV_TRACE = 4,         // covariance trace exceeds maximum (trace > 1000 m)
		TEST_DIST = 5,   // test distance exceeded (max of 3 rejections if distance >
		// 10 km)
		COLD_START = 6,  // not yet converged from cold start
		V_H_LIMIT = 7,   // height or velocity limits exceeded
		VARIANCE = 8,    // variance exceeds limits
		RESIDUALS = 9,   // residuals are too large
		INTEGRITY_WARNING = 13,  // large residuals make position questionable
		PENDING = 18,  // receiver computes its position and determines if the fixed
		// position is valid
		INVALID_FIX = 19,   // the fixed position entered using the fix position
		// command is invalid
		UNAUTHORIZED = 20,  // position type is unauthorized
		INVALID_RATE =
		22  // selected logging rate is not supported for this solution type
	};
}
namespace apollo::drivers::gnss{
	enum SolutionType {
		NONE = 0,
		FIXEDPOS = 1,
		FIXEDHEIGHT = 2,
		FLOATCONV = 4,
		WIDELANE = 5,
		NARROWLANE = 6,
		DOPPLER_VELOCITY = 8,
		SINGLE = 16,
		PSRDIFF = 17,
		WAAS = 18,
		PROPOGATED = 19,
		OMNISTAR = 20,
		L1_FLOAT = 32,
		IONOFREE_FLOAT = 33,
		NARROW_FLOAT = 34,
		L1_INT = 48,
		WIDE_INT = 49,
		NARROW_INT = 50,
		RTK_DIRECT_INS =
		51,  // RTK filter is directly initialized from the INS filter.
		INS_SBAS = 52,
		INS_PSRSP = 53,
		INS_PSRDIFF = 54,
		INS_RTKFLOAT = 55,
		INS_RTKFIXED = 56,
		INS_OMNISTAR = 57,
		INS_OMNISTAR_HP = 58,
		INS_OMNISTAR_XP = 59,
		OMNISTAR_HP = 64,
		OMNISTAR_XP = 65,
		PPP_CONVERGING = 68,
		PPP = 69,
		INS_PPP_CONVERGING = 73,
		INS_PPP = 74
	};
}
namespace apollo::drivers::gnss{
	enum DatumId {
		// We only use WGS-84.
		WGS84 = 61
	};
}