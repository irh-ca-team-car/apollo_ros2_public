#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodrivers_ldw_lane_boundary.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_lane_boundary.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversLdwLaneBoundary LdwLaneBoundary;
}
#include "apollo_msgs/msg/apollodrivers_ldw_lane.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_lane.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversLdwLane LdwLane;
}
#include "apollo_msgs/msg/apollodrivers_ldw_roadway.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_roadway.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversLdwRoadway LdwRoadway;
}
#include "apollo_msgs/msg/apollodrivers_ldw_lens_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_lens_info.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversLdwLensInfo LdwLensInfo;
}
#include "apollo_msgs/msg/apollodrivers_ldw_data_packs.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_data_packs.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversLdwDataPacks LdwDataPacks;
}
#include "apollo_msgs/msg/apollodrivers_output_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_output_obstacle.hpp"
#include "apollo_msgs/msg/apollodrivers_smartereye_obstacles.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_smartereye_obstacles.hpp"
#include "apollo_msgs/msg/apollodrivers_smartereye_lanemark.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_smartereye_lanemark.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversSmartereyeLanemark SmartereyeLanemark;
}
namespace apollo::drivers{
	enum LdwVersions {
		LDW_VERSION_C1 = 0,
		LDW_VERSION_C2 = 1,
		LDW_VERSION_FOUR_LANE_C2 = 2
	};
}
namespace apollo::drivers{
	enum LdwLaneStyle {
		LDW_LANE_STYLE_NONE_LANE = 0,
		LDW_LANE_STYLE_PREDICT_LANE = 1,
		LDW_LANE_STYLE_BROKEN_LANE = 2,
		LDW_LANE_STYLE_SOLID_LANE = 3,
		LDW_LANE_STYLE_DOUBLE_BROKEN_LANE = 4,
		LDW_LANE_STYLE_DOUBLE_SOLID_LANE = 5,
		LDW_LANE_STYLE_TRIPLE_LANE = 6
	};
}
namespace apollo::drivers{
	enum LdwSteerStatus {
		LDW_NORMAL_STEER = 0,
		LDW_STEER_ON_LEFT__LANE = 1,
		LDW_STEER_ON_RIGHT_LANE = 2,
		LDW_STEER_WARNING_LEFT_ = 3,
		LDW_STEER_WARNING_RIGHT = 4
	};
}
namespace apollo::drivers{
	enum LdwSoftStatus {
		LDW_SOFT_DETECTION = 0,
		LDW_SOFT_SELF_LEARNING = 1,
		LDW_SOFT_MANUAL_LEARNING_MODE0 = 2,
		LDW_SOFT_MANUAL_LEARNING_MODE1 = 3
	};
}
namespace apollo::drivers{
	enum LdwWarningGrade {
		LDW_WARNING_LOW = 0,
		LDW_WARNING_NORMAL = 1,
		LDW_WARNING_HIGHT = 2
	};
}
namespace apollo::drivers::OutputObstacle{
	enum RecognitionType {
		INVALID = 0,
		VEHICLE = 1,
		PEDESTRIAN = 2,
		CHILD = 3,
		BICYCLE = 4,
		MOTO = 5,
		TRUCK = 6,
		BUS = 7,
		OTHERS = 8,
		ESTIMATED = 9,
		CONTINUOUS = 10
	};
}