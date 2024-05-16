#pragma once
#include "apollo_msgs/msg/apollov2xftfusion_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionParam &msg) ;
    Apollov2xftfusionParam from_json_Apollov2xftfusionParam (nlohmann::json obj) ;
    template <>
    Apollov2xftfusionParam from_json<Apollov2xftfusionParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionParam &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionParam & dt);
}
