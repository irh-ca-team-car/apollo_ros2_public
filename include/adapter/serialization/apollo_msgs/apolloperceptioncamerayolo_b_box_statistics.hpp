#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerayolo_b_box_statistics.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerayoloBBoxStatistics &msg) ;
    ApolloperceptioncamerayoloBBoxStatistics from_json_ApolloperceptioncamerayoloBBoxStatistics (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerayoloBBoxStatistics from_json<ApolloperceptioncamerayoloBBoxStatistics>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerayoloBBoxStatistics &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerayoloBBoxStatistics & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerayoloBBoxStatistics & dt);
}
