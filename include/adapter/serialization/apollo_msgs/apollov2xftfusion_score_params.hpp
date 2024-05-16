#pragma once
#include "apollo_msgs/msg/apollov2xftfusion_score_params.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionScoreParams &msg) ;
    Apollov2xftfusionScoreParams from_json_Apollov2xftfusionScoreParams (nlohmann::json obj) ;
    template <>
    Apollov2xftfusionScoreParams from_json<Apollov2xftfusionScoreParams>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionScoreParams &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionScoreParams & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionScoreParams & dt);
}
