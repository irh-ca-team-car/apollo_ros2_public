#pragma once
#include "apollo_msgs/msg/apollov2xftfusion_km_params.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xftfusion_km_params.hpp"
namespace apollo::v2x::ft::fusion{
	typedef apollo_msgs::msg::Apollov2xftfusionKMParams KMParams;
}
#include "apollo_msgs/msg/apollov2xftfusion_param.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xftfusion_param.hpp"
namespace apollo::v2x::ft::fusion{
	typedef apollo_msgs::msg::Apollov2xftfusionParam Param;
}
#include "apollo_msgs/msg/apollov2xftfusion_single_camera_param.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xftfusion_single_camera_param.hpp"
namespace apollo::v2x::ft::fusion{
	typedef apollo_msgs::msg::Apollov2xftfusionSingleCameraParam SingleCameraParam;
}
#include "apollo_msgs/msg/apollov2xftfusion_score_params.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xftfusion_score_params.hpp"
namespace apollo::v2x::ft::fusion{
	typedef apollo_msgs::msg::Apollov2xftfusionScoreParams ScoreParams;
}
#include "apollo_msgs/msg/apollov2xftfusion_fusion_params.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xftfusion_fusion_params.hpp"
namespace apollo::v2x::ft::fusion{
	typedef apollo_msgs::msg::Apollov2xftfusionFusionParams FusionParams;
}
namespace apollo::v2x::ft::fusion{
	enum ConfidenceLevel {
		C90P = 0,
		C95P = 1,
		C975P = 2,
		C99P = 3
	};
}