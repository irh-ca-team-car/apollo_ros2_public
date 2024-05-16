#pragma once
#include "apollo_msgs/msg/apolloperceptioncameralane_lane_postprocessor_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameralaneLanePostprocessorParam &msg) ;
    ApolloperceptioncameralaneLanePostprocessorParam from_json_ApolloperceptioncameralaneLanePostprocessorParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameralaneLanePostprocessorParam from_json<ApolloperceptioncameralaneLanePostprocessorParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameralaneLanePostprocessorParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameralaneLanePostprocessorParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameralaneLanePostprocessorParam & dt);
}
