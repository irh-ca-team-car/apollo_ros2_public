#pragma once
#include "apollo_msgs/msg/apolloperceptionfusion_dst_type_fusion_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_camera_dst_type_fusion_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_lidar_dst_type_fusion_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionDstTypeFusionConfig &msg) ;
    ApolloperceptionfusionDstTypeFusionConfig from_json_ApolloperceptionfusionDstTypeFusionConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionfusionDstTypeFusionConfig from_json<ApolloperceptionfusionDstTypeFusionConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionDstTypeFusionConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionDstTypeFusionConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionDstTypeFusionConfig & dt);
}
