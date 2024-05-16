#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_b_box3_d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBBox3D &msg) ;
    ApolloperceptioninferenceBBox3D from_json_ApolloperceptioninferenceBBox3D (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceBBox3D from_json<ApolloperceptioninferenceBBox3D>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBBox3D &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBBox3D & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBBox3D & dt);
}
