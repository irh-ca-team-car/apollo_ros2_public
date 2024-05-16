#pragma once
#include "modules/drivers/canbus/proto/can_card_parameter.pb.h"
#include "apollo_msgs/msg/apollodriversconti_radar_can_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversconti_radar_can_conf.hpp"
namespace apollo::drivers::conti_radar{
	typedef apollo_msgs::msg::ApollodriverscontiRadarCanConf CanConf;
}
#include "apollo_msgs/msg/apollodriversconti_radar_radar_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversconti_radar_radar_conf.hpp"
namespace apollo::drivers::conti_radar{
	typedef apollo_msgs::msg::ApollodriverscontiRadarRadarConf RadarConf;
}
#include "apollo_msgs/msg/apollodriversconti_radar_conti_radar_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversconti_radar_conti_radar_conf.hpp"
namespace apollo::drivers::conti_radar{
	typedef apollo_msgs::msg::ApollodriverscontiRadarContiRadarConf ContiRadarConf;
}
namespace apollo::drivers::conti_radar{
	enum OutputType {
		OUTPUT_TYPE_NONE = 0,
		OUTPUT_TYPE_OBJECTS = 1,
		OUTPUT_TYPE_CLUSTERS = 2,
		OUTPUT_TYPE_ERROR = 3
	};
}
namespace apollo::drivers::conti_radar{
	enum RcsThreshold {
		RCS_THRESHOLD_STANDARD = 0,
		RCS_THRESHOLD_HIGH_SENSITIVITY = 1,
		RCS_THRESHOLD_ERROR = 2
	};
}