#pragma once
#include "apollo_msgs/msg/apollov2x_update_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xUpdateStatus &msg) ;
    Apollov2xUpdateStatus from_json_Apollov2xUpdateStatus (nlohmann::json obj) ;
    template <>
    Apollov2xUpdateStatus from_json<Apollov2xUpdateStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xUpdateStatus &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xUpdateStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xUpdateStatus & dt);
}
