#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_lane_perception_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_detector_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_plugin_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappLanePerceptionParam &msg) ;
    ApolloperceptioncameraappLanePerceptionParam from_json_ApolloperceptioncameraappLanePerceptionParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappLanePerceptionParam from_json<ApolloperceptioncameraappLanePerceptionParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappLanePerceptionParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappLanePerceptionParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappLanePerceptionParam & dt);
}
