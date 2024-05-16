#pragma once
#include "modules/planning/proto/math/cos_theta_smoother_config.pb.h"
#include "modules/planning/proto/math/fem_pos_deviation_smoother_config.pb.h"
#include "apollo_msgs/msg/apolloplanning_qp_spline_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_qp_spline_smoother_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningQpSplineSmootherConfig QpSplineSmootherConfig;
}
#include "apollo_msgs/msg/apolloplanning_spiral_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_spiral_smoother_config.hpp"
namespace apollo::planning{
	typedef apollo_msgs::msg::ApolloplanningSpiralSmootherConfig SpiralSmootherConfig;
}
#include "apollo_msgs/msg/apolloplanning_discrete_points_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_discrete_points_smoother_config.hpp"
#include "apollo_msgs/msg/apolloplanning_reference_line_smoother_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_reference_line_smoother_config.hpp"
namespace apollo::planning::DiscretePointsSmootherConfig{
	enum SmoothingMethod {
		NOT_DEFINED = 0,
		COS_THETA_SMOOTHING = 1,
		FEM_POS_DEVIATION_SMOOTHING = 2
	};
}