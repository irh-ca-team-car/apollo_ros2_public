#pragma once
#include "apollo_msgs/msg/apollostorytelling_close_to_stop_sign.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToStopSign &msg) ;
    ApollostorytellingCloseToStopSign from_json_ApollostorytellingCloseToStopSign (nlohmann::json obj) ;
    template <>
    ApollostorytellingCloseToStopSign from_json<ApollostorytellingCloseToStopSign>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToStopSign &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToStopSign & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToStopSign & dt);
}
