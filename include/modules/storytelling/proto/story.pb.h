#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollostorytelling_close_to_crosswalk.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_crosswalk.hpp"
namespace apollo::storytelling{
	typedef apollo_msgs::msg::ApollostorytellingCloseToCrosswalk CloseToCrosswalk;
}
#include "apollo_msgs/msg/apollostorytelling_close_to_clear_area.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_clear_area.hpp"
namespace apollo::storytelling{
	typedef apollo_msgs::msg::ApollostorytellingCloseToClearArea CloseToClearArea;
}
#include "apollo_msgs/msg/apollostorytelling_close_to_junction.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_junction.hpp"
#include "apollo_msgs/msg/apollostorytelling_close_to_signal.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_signal.hpp"
namespace apollo::storytelling{
	typedef apollo_msgs::msg::ApollostorytellingCloseToSignal CloseToSignal;
}
#include "apollo_msgs/msg/apollostorytelling_close_to_stop_sign.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_stop_sign.hpp"
namespace apollo::storytelling{
	typedef apollo_msgs::msg::ApollostorytellingCloseToStopSign CloseToStopSign;
}
#include "apollo_msgs/msg/apollostorytelling_close_to_yield_sign.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_yield_sign.hpp"
namespace apollo::storytelling{
	typedef apollo_msgs::msg::ApollostorytellingCloseToYieldSign CloseToYieldSign;
}
#include "apollo_msgs/msg/apollostorytelling_stories.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_stories.hpp"
namespace apollo::storytelling{
	typedef apollo_msgs::msg::ApollostorytellingStories Stories;
}
namespace apollo::storytelling::CloseToJunction{
	enum JunctionType {
		PNC_JUNCTION = 1,
		JUNCTION = 2
	};
}