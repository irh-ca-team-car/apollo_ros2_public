#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_dim.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_dim.hpp"
namespace apollo::perception::camera{
	typedef apollo_msgs::msg::ApolloperceptioncameraDim Dim;
}
#include "apollo_msgs/msg/apolloperceptioncamera_object_template.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_object_template.hpp"
namespace apollo::perception::camera{
	typedef apollo_msgs::msg::ApolloperceptioncameraObjectTemplate ObjectTemplate;
}
#include "apollo_msgs/msg/apolloperceptioncamera_object_template_meta.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_object_template_meta.hpp"
namespace apollo::perception::camera{
	typedef apollo_msgs::msg::ApolloperceptioncameraObjectTemplateMeta ObjectTemplateMeta;
}