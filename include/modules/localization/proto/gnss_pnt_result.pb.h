#pragma once
#include "modules/drivers/gnss/proto/gnss_raw_observation.pb.h"
#include "apollo_msgs/msg/apollolocalization_sat_dir_cosine.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_sat_dir_cosine.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationSatDirCosine SatDirCosine;
}
#include "apollo_msgs/msg/apollolocalization_gnss_pnt_result.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_gnss_pnt_result.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationGnssPntResult GnssPntResult;
}
namespace apollo::localization{
	enum PntType {
		PNT_INVALID = 0,
		PNT_SPP = 1,
		PNT_PHASE_TD = 2,
		PNT_CODE_DIFF = 3,
		PNT_RTK_FLOAT = 4,
		PNT_RTK_FIXED = 5
	};
}