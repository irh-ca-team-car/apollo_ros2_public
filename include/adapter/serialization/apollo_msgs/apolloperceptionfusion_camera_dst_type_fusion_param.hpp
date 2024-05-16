#pragma once
#include "apollo_msgs/msg/apolloperceptionfusion_camera_dst_type_fusion_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionCameraDstTypeFusionParam &msg) ;
    ApolloperceptionfusionCameraDstTypeFusionParam from_json_ApolloperceptionfusionCameraDstTypeFusionParam (nlohmann::json obj) ;
    template <>
    ApolloperceptionfusionCameraDstTypeFusionParam from_json<ApolloperceptionfusionCameraDstTypeFusionParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionCameraDstTypeFusionParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionCameraDstTypeFusionParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionCameraDstTypeFusionParam & dt);
}
