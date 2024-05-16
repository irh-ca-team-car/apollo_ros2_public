#pragma once
#include "apollo_msgs/msg/apolloperceptionfusion_lidar_dst_type_fusion_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionLidarDstTypeFusionParam &msg) ;
    ApolloperceptionfusionLidarDstTypeFusionParam from_json_ApolloperceptionfusionLidarDstTypeFusionParam (nlohmann::json obj) ;
    template <>
    ApolloperceptionfusionLidarDstTypeFusionParam from_json<ApolloperceptionfusionLidarDstTypeFusionParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionLidarDstTypeFusionParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionLidarDstTypeFusionParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionLidarDstTypeFusionParam & dt);
}
