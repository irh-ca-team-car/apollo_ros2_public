#pragma once
#include "apollo_msgs/msg/apollolocalization_localization_config.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_localization_config.hpp"
namespace apollo::localization::LocalizationConfig{
	enum LocalizationType {
		RTK = 0,
		MSF = 1
	};
}