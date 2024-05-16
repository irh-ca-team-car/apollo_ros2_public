#pragma once
#include "apollo_msgs/msg/apollov2x_status_response.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xStatusResponse &msg) ;
    Apollov2xStatusResponse from_json_Apollov2xStatusResponse (nlohmann::json obj) ;
    template <>
    Apollov2xStatusResponse from_json<Apollov2xStatusResponse>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xStatusResponse &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xStatusResponse & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xStatusResponse & dt);
}
