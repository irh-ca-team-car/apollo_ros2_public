#pragma once
#include "apollo_msgs/msg/apollostorytelling_close_to_clear_area.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToClearArea &msg) ;
    ApollostorytellingCloseToClearArea from_json_ApollostorytellingCloseToClearArea (nlohmann::json obj) ;
    template <>
    ApollostorytellingCloseToClearArea from_json<ApollostorytellingCloseToClearArea>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToClearArea &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToClearArea & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToClearArea & dt);
}
