#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratraffic_lightrecognition_recognize_box_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameratraffic_lightrecognition_classify_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam &msg) ;
    ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam from_json_ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam from_json<ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam & dt);
}
