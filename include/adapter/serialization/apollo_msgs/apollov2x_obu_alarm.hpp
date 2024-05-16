#pragma once
#include "apollo_msgs/msg/apollov2x_obu_alarm.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xObuAlarm &msg) ;
    Apollov2xObuAlarm from_json_Apollov2xObuAlarm (nlohmann::json obj) ;
    template <>
    Apollov2xObuAlarm from_json<Apollov2xObuAlarm>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xObuAlarm &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xObuAlarm & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xObuAlarm & dt);
}
