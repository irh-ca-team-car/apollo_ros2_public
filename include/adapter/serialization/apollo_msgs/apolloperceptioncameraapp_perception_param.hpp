#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_perception_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_detector_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_tracker_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_transformer_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_postprocessor_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_feature_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_lane_perception_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_calibration_service_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_debug_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_object_template_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappPerceptionParam &msg) ;
    ApolloperceptioncameraappPerceptionParam from_json_ApolloperceptioncameraappPerceptionParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappPerceptionParam from_json<ApolloperceptioncameraappPerceptionParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappPerceptionParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappPerceptionParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappPerceptionParam & dt);
}
