#pragma once
#include "apollo_msgs/msg/apollov2xftfusion_single_camera_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2xftfusion_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionSingleCameraParam &msg) ;
    Apollov2xftfusionSingleCameraParam from_json_Apollov2xftfusionSingleCameraParam (nlohmann::json obj) ;
    template <>
    Apollov2xftfusionSingleCameraParam from_json<Apollov2xftfusionSingleCameraParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionSingleCameraParam &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionSingleCameraParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionSingleCameraParam & dt);
}
