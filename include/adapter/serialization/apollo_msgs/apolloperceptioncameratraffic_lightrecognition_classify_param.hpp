#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratraffic_lightrecognition_classify_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrafficLightrecognitionClassifyParam &msg) ;
    ApolloperceptioncameratrafficLightrecognitionClassifyParam from_json_ApolloperceptioncameratrafficLightrecognitionClassifyParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameratrafficLightrecognitionClassifyParam from_json<ApolloperceptioncameratrafficLightrecognitionClassifyParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrafficLightrecognitionClassifyParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrafficLightrecognitionClassifyParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrafficLightrecognitionClassifyParam & dt);
}
