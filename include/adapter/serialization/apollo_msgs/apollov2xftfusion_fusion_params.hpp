#pragma once
#include "apollo_msgs/msg/apollov2xftfusion_fusion_params.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2xftfusion_single_camera_param.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xftfusion_km_params.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xftfusion_score_params.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionFusionParams &msg) ;
    Apollov2xftfusionFusionParams from_json_Apollov2xftfusionFusionParams (nlohmann::json obj) ;
    template <>
    Apollov2xftfusionFusionParams from_json<Apollov2xftfusionFusionParams>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionFusionParams &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionFusionParams & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionFusionParams & dt);
}
