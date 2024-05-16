#pragma once
#include "apollo_msgs/msg/apollostorytelling_close_to_crosswalk.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToCrosswalk &msg) ;
    ApollostorytellingCloseToCrosswalk from_json_ApollostorytellingCloseToCrosswalk (nlohmann::json obj) ;
    template <>
    ApollostorytellingCloseToCrosswalk from_json<ApollostorytellingCloseToCrosswalk>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToCrosswalk &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToCrosswalk & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToCrosswalk & dt);
}
