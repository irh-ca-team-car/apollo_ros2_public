#pragma once
#include "apollo_msgs/msg/apolloperceptioncameradark_scnn_dark_scnn_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradark_scnn_dark_scnn_param.hpp"
namespace apollo::perception::camera::darkSCNN{
	typedef apollo_msgs::msg::ApolloperceptioncameradarkSCNNDarkSCNNParam DarkSCNNParam;
}
#include "apollo_msgs/msg/apolloperceptioncameradark_scnn_model_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradark_scnn_model_param.hpp"
namespace apollo::perception::camera::darkSCNN{
	typedef apollo_msgs::msg::ApolloperceptioncameradarkSCNNModelParam ModelParam;
}
#include "apollo_msgs/msg/apolloperceptioncameradark_scnn_network_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameradark_scnn_network_param.hpp"
namespace apollo::perception::camera::darkSCNN{
	typedef apollo_msgs::msg::ApolloperceptioncameradarkSCNNNetworkParam NetworkParam;
}