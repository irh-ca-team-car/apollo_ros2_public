#pragma once
#include "modules/drivers/canbus/proto/can_card_parameter.pb.h"
#include "apollo_msgs/msg/apollodriversracobit_radar_can_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversracobit_radar_can_conf.hpp"
namespace apollo::drivers::racobit_radar{
	typedef apollo_msgs::msg::ApollodriversracobitRadarCanConf CanConf;
}
#include "apollo_msgs/msg/apollodriversracobit_radar_radar_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversracobit_radar_radar_conf.hpp"
namespace apollo::drivers::racobit_radar{
	typedef apollo_msgs::msg::ApollodriversracobitRadarRadarConf RadarConf;
}
#include "apollo_msgs/msg/apollodriversracobit_radar_racobit_radar_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversracobit_radar_racobit_radar_conf.hpp"
namespace apollo::drivers::racobit_radar{
	typedef apollo_msgs::msg::ApollodriversracobitRadarRacobitRadarConf RacobitRadarConf;
}
namespace apollo::drivers::racobit_radar{
	enum OutputType {
		OUTPUT_TYPE_NONE = 0,
		OUTPUT_TYPE_OBJECTS = 1,
		OUTPUT_TYPE_CLUSTERS = 2,
		OUTPUT_TYPE_ERROR = 3
	};
}
namespace apollo::drivers::racobit_radar{
	enum RcsThreshold {
		RCS_THRESHOLD_STANDARD = 0,
		RCS_THRESHOLD_HIGH_SENSITIVITY = 1,
		RCS_THRESHOLD_ERROR = 2
	};
}