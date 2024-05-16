#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodriversgnss_stream_status.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_stream_status.hpp"
#include "apollo_msgs/msg/apollodriversgnss_ins_status.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_ins_status.hpp"
#include "apollo_msgs/msg/apollodriversgnss_gnss_status.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_gnss_status.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssGnssStatus GnssStatus;
}
namespace apollo::drivers::gnss::StreamStatus{
	enum Type {
		DISCONNECTED = 0,
		CONNECTED = 1
	};
}
namespace apollo::drivers::gnss::InsStatus{
	enum Type {
		// Invalid solution due to insufficient observations, no initial GNSS, ...
		INVALID = 0,
		
		// Use with caution. The covariance matrix may be unavailable or incorrect.
		// High-variance result due to aligning, insufficient vehicle dynamics, ...
		CONVERGING = 1,
		
		// Safe to use. The INS has fully converged.
		GOOD = 2
	};
}