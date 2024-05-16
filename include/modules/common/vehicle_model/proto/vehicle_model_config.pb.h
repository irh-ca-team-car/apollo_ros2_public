#pragma once
#include "apollo_msgs/msg/apollocommon_vehicle_model_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_model_config.hpp"
#include "apollo_msgs/msg/apollocommon_rear_centered_kinematic_bicycle_model_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_rear_centered_kinematic_bicycle_model_config.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonRearCenteredKinematicBicycleModelConfig RearCenteredKinematicBicycleModelConfig;
}
#include "apollo_msgs/msg/apollocommon_com_centered_dynamic_bicycle_model_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_com_centered_dynamic_bicycle_model_config.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonComCenteredDynamicBicycleModelConfig ComCenteredDynamicBicycleModelConfig;
}
#include "apollo_msgs/msg/apollocommon_mlp_model_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_mlp_model_config.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonMlpModelConfig MlpModelConfig;
}
namespace apollo::common::VehicleModelConfig{
	enum ModelType {
		REAR_CENTERED_KINEMATIC_BICYCLE_MODEL = 0,
		COM_CENTERED_DYNAMIC_BICYCLE_MODEL = 1,
		MLP_MODEL = 2
	};
}