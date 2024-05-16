#pragma once
#include "modules/canbus/proto/canbus_conf.pb.h"
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/common/configs/proto/vehicle_config.pb.h"
#include "modules/control/proto/control_conf.pb.h"
#include "modules/routing/proto/routing.pb.h"
#include "apollo_msgs/msg/apollodata_vehicle_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_vehicle_info.hpp"
#include "apollo_msgs/msg/apollodata_environment_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_environment_info.hpp"
namespace apollo::data{
	typedef apollo_msgs::msg::ApollodataEnvironmentInfo EnvironmentInfo;
}
#include "apollo_msgs/msg/apollodata_hardware_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_hardware_info.hpp"
#include "apollo_msgs/msg/apollodata_software_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_software_info.hpp"
#include "apollo_msgs/msg/apollodata_user_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_user_info.hpp"
namespace apollo::data{
	typedef apollo_msgs::msg::ApollodataUserInfo UserInfo;
}
#include "apollo_msgs/msg/apollodata_static_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_static_info.hpp"
namespace apollo::data{
	typedef apollo_msgs::msg::ApollodataStaticInfo StaticInfo;
}
#include "apollo_msgs/msg/apollodata_static_info_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_static_info_conf.hpp"
namespace apollo::data{
	typedef apollo_msgs::msg::ApollodataStaticInfoConf StaticInfoConf;
}
namespace apollo::data::VehicleInfo{
	enum Brand {
		LINCOLN = 1,
		FORD = 2,
		LEXUS = 3
	};
}
namespace apollo::data::VehicleInfo{
	enum Model {
		// Lincoln model
		MKZ = 1,
		TRANSIT = 2,
		RX450H = 3
	};
}