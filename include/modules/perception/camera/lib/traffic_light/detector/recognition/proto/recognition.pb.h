#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratraffic_lightrecognition_classify_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratraffic_lightrecognition_classify_param.hpp"
namespace apollo::perception::camera::traffic_light::recognition{
	typedef apollo_msgs::msg::ApolloperceptioncameratrafficLightrecognitionClassifyParam ClassifyParam;
}
#include "apollo_msgs/msg/apolloperceptioncameratraffic_lightrecognition_recognize_box_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratraffic_lightrecognition_recognize_box_param.hpp"
namespace apollo::perception::camera::traffic_light::recognition{
	typedef apollo_msgs::msg::ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam RecognizeBoxParam;
}