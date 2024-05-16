#pragma once
#include "apollo_msgs/msg/apolloperceptioncameralane_dark_scnn_lane_postprocessor_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam &msg) ;
    ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam from_json_ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam from_json<ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam & dt);
}
