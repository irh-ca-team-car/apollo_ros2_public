#pragma once
#include "apollo_msgs/msg/apolloperceptioncameradenseline_denseline_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradenseline_denseline_param.hpp"
namespace apollo::perception::camera::denseline{
	typedef apollo_msgs::msg::ApolloperceptioncameradenselineDenselineParam DenselineParam;
}
#include "apollo_msgs/msg/apolloperceptioncameradenseline_model_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradenseline_model_param.hpp"
namespace apollo::perception::camera::denseline{
	typedef apollo_msgs::msg::ApolloperceptioncameradenselineModelParam ModelParam;
}
#include "apollo_msgs/msg/apolloperceptioncameradenseline_network_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradenseline_network_param.hpp"
namespace apollo::perception::camera::denseline{
	typedef apollo_msgs::msg::ApolloperceptioncameradenselineNetworkParam NetworkParam;
}