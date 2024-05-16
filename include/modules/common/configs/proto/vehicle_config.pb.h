#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollocommon_transform.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_transform.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonTransform Transform;
}
#include "apollo_msgs/msg/apollocommon_extrinsics.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_extrinsics.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonExtrinsics Extrinsics;
}
#include "apollo_msgs/msg/apollocommon_vehicle_id.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_id.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonVehicleID VehicleID;
}
#include "apollo_msgs/msg/apollocommon_latency_param.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_param.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonLatencyParam LatencyParam;
}
#include "apollo_msgs/msg/apollocommon_vehicle_param.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_param.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonVehicleParam VehicleParam;
}
#include "apollo_msgs/msg/apollocommon_vehicle_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_config.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonVehicleConfig VehicleConfig;
}
namespace apollo::common{
	enum VehicleBrand {
		LINCOLN_MKZ = 0,
		GEM = 1,
		LEXUS = 2,
		TRANSIT = 3,
		GE3 = 4,
		WEY = 5,
		ZHONGYUN = 6,
		CH = 7,
		DKIT = 8,
		NEOLIX = 9
	};
}