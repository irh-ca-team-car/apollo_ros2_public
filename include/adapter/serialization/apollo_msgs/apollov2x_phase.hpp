#pragma once
#include "apollo_msgs/msg/apollov2x_phase.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xPhase &msg) ;
    Apollov2xPhase from_json_Apollov2xPhase (nlohmann::json obj) ;
    template <>
    Apollov2xPhase from_json<Apollov2xPhase>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xPhase &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xPhase & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xPhase & dt);
}
