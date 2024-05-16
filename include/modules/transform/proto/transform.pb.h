#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollotransform_transform.hpp"
#include "adapter/serialization/apollo_msgs/apollotransform_transform.hpp"
namespace apollo::transform{
	typedef apollo_msgs::msg::ApollotransformTransform Transform;
}
#include "geometry_msgs/msg/transform_stamped.hpp"
namespace apollo::transform{
	typedef geometry_msgs::msg::TransformStamped TransformStamped;
}
#include "tf2_msgs/msg/tf_message.hpp"
namespace apollo::transform{
	typedef tf2_msgs::msg::TFMessage TransformStampeds;
}