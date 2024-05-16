#pragma once
#include "apollo_msgs/msg/apollov2xftfusion_km_params.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionKMParams &msg) ;
    Apollov2xftfusionKMParams from_json_Apollov2xftfusionKMParams (nlohmann::json obj) ;
    template <>
    Apollov2xftfusionKMParams from_json<Apollov2xftfusionKMParams>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionKMParams &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionKMParams & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionKMParams & dt);
}
