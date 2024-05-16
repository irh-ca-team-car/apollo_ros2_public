#pragma once
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/common/proto/drive_state.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/common/proto/vehicle_signal.pb.h"
#include "modules/control/proto/input_debug.pb.h"
#include "modules/control/proto/pad_msg.pb.h"
#include "apollo_msgs/msg/apollocontrol_latency_stats.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_latency_stats.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolLatencyStats LatencyStats;
}
#include "apollo_msgs/msg/apollocontrol_control_command.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_control_command.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolControlCommand ControlCommand;
}
#include "apollo_msgs/msg/apollocontrol_simple_longitudinal_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_simple_longitudinal_debug.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolSimpleLongitudinalDebug SimpleLongitudinalDebug;
}
#include "apollo_msgs/msg/apollocontrol_simple_lateral_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_simple_lateral_debug.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolSimpleLateralDebug SimpleLateralDebug;
}
#include "apollo_msgs/msg/apollocontrol_simple_mpc_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_simple_mpc_debug.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolSimpleMPCDebug SimpleMPCDebug;
}
#include "apollo_msgs/msg/apollocontrol_mrac_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_mrac_debug.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolMracDebug MracDebug;
}
#include "apollo_msgs/msg/apollocontrol_mrac_adaptive_gain.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_mrac_adaptive_gain.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolMracAdaptiveGain MracAdaptiveGain;
}
#include "apollo_msgs/msg/apollocontrol_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_debug.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolDebug Debug;
}
namespace apollo::control{
	enum TurnSignal {
		TURN_NONE = 0,
		TURN_LEFT = 1,
		TURN_RIGHT = 2
	};
}