#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollodriversgnss_ins_stat.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_ins_stat.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssInsStat InsStat;
}
#include "apollo_msgs/msg/apollodriversgnss_ins.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_ins.hpp"
namespace apollo::drivers::gnss::Ins{
	enum Type {
		// Do NOT use.
		// Invalid solution due to insufficient observations, no initial GNSS, ...
		INVALID = 0,
		
		// Use with caution. The covariance matrix may be unavailable or incorrect.
		// High-variance result due to aligning, insufficient vehicle dynamics, ...
		CONVERGING = 1,
		
		// Safe to use. The INS has fully converged.
		GOOD = 2
	};
}