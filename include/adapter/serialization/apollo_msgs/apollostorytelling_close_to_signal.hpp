#pragma once
#include "apollo_msgs/msg/apollostorytelling_close_to_signal.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToSignal &msg) ;
    ApollostorytellingCloseToSignal from_json_ApollostorytellingCloseToSignal (nlohmann::json obj) ;
    template <>
    ApollostorytellingCloseToSignal from_json<ApollostorytellingCloseToSignal>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToSignal &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToSignal & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToSignal & dt);
}
