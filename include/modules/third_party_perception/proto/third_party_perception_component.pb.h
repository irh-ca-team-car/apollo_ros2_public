#pragma once
#include "apollo_msgs/msg/apollothird_party_perception_third_party_perception_device.hpp"
#include "adapter/serialization/apollo_msgs/apollothird_party_perception_third_party_perception_device.hpp"
namespace apollo::third_party_perception{
	typedef apollo_msgs::msg::ApollothirdPartyPerceptionThirdPartyPerceptionDevice ThirdPartyPerceptionDevice;
}
namespace apollo::third_party_perception{
	enum ThirdPartyPerceptionDeviceType {
		SMARTEREYE = 0,
		MOBILEYE = 1
	};
}