#pragma once
#include "apollo_msgs/msg/apolloperceptioncamera_dim.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraDim &msg) ;
    ApolloperceptioncameraDim from_json_ApolloperceptioncameraDim (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraDim from_json<ApolloperceptioncameraDim>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraDim &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraDim & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraDim & dt);
}
