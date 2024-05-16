#pragma once
#include "apollo_msgs/msg/apolloplanning_backside_vehicle_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_backside_vehicle_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningBacksideVehicleConfig BacksideVehicleConfig;
}
#include "apollo_msgs/msg/apolloplanning_crosswalk_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_crosswalk_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningCrosswalkConfig CrosswalkConfig;
}
#include "apollo_msgs/msg/apolloplanning_destination_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_destination_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningDestinationConfig DestinationConfig;
}
#include "apollo_msgs/msg/apolloplanning_keep_clear_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_keep_clear_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningKeepClearConfig KeepClearConfig;
}
#include "apollo_msgs/msg/apolloplanning_reference_line_end_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_reference_line_end_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningReferenceLineEndConfig ReferenceLineEndConfig;
}
#include "apollo_msgs/msg/apolloplanning_rerouting_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_rerouting_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningReroutingConfig ReroutingConfig;
}
#include "apollo_msgs/msg/apolloplanning_stop_sign_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_stop_sign_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningStopSignConfig StopSignConfig;
}
#include "apollo_msgs/msg/apolloplanning_traffic_light_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTrafficLightConfig TrafficLightConfig;
}
#include "apollo_msgs/msg/apolloplanning_yield_sign_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_yield_sign_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningYieldSignConfig YieldSignConfig;
}
#include "apollo_msgs/msg/apolloplanning_traffic_rule_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_rule_config.hpp"
#include "apollo_msgs/msg/apolloplanning_traffic_rule_configs.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_rule_configs.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningTrafficRuleConfigs TrafficRuleConfigs;
}
namespace apollo::planning::TrafficRuleConfig{
	enum RuleId {
		BACKSIDE_VEHICLE = 1,
		CROSSWALK = 2,
		DESTINATION = 3,
		KEEP_CLEAR = 4,
		REFERENCE_LINE_END = 5,
		REROUTING = 6,
		STOP_SIGN = 7,
		TRAFFIC_LIGHT = 8,
		YIELD_SIGN = 9
	};
}

#include "modules/planning/proto/traffic_rule_config_name.pb.h"