#pragma once
#include "apollo_msgs/msg/apollodreamview_criterion.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_criterion.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewCriterion Criterion;
}
#include "apollo_msgs/msg/apollodreamview_range.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_range.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewRange Range;
}
#include "apollo_msgs/msg/apollodreamview_feature.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_feature.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewFeature Feature;
}
#include "apollo_msgs/msg/apollodreamview_scenario.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_scenario.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewScenario Scenario;
}
#include "apollo_msgs/msg/apollodreamview_data_collection_table.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_data_collection_table.hpp"
namespace apollo::dreamview{
	enum ComparisonOperator {
		EQUAL = 0,
		NOT_EQUAL = 1,
		GREATER_THAN = 2,
		GREATER_THAN_OR_EQUAL = 3,
		LESS_THAN = 4,
		LESS_THAN_OR_EQUAL = 5
	};
}