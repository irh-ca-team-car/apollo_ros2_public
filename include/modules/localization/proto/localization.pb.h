#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/localization/proto/pose.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/localization/proto/localization_status.pb.h"
#include "apollo_msgs/msg/apollolocalization_uncertainty.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_uncertainty.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationUncertainty Uncertainty;
}
#include "apollo_msgs/msg/apollolocalization_localization_estimate.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_localization_estimate.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationLocalizationEstimate LocalizationEstimate;
}
#include "apollo_msgs/msg/apollolocalization_localization_status.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_localization_status.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationLocalizationStatus LocalizationStatus;
}
namespace apollo::localization{
	enum MeasureState {
		OK = 0,
		WARNNING = 1,
		ERROR = 2,
		CRITICAL_ERROR = 3,
		FATAL_ERROR = 4
	};
}