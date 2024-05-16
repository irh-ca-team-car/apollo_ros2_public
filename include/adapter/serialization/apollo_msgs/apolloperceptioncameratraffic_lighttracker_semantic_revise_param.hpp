#pragma once
#include "apollo_msgs/msg/apolloperceptioncameratraffic_lighttracker_semantic_revise_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrafficLighttrackerSemanticReviseParam &msg) ;
    ApolloperceptioncameratrafficLighttrackerSemanticReviseParam from_json_ApolloperceptioncameratrafficLighttrackerSemanticReviseParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameratrafficLighttrackerSemanticReviseParam from_json<ApolloperceptioncameratrafficLighttrackerSemanticReviseParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrafficLighttrackerSemanticReviseParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrafficLighttrackerSemanticReviseParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrafficLighttrackerSemanticReviseParam & dt);
}
