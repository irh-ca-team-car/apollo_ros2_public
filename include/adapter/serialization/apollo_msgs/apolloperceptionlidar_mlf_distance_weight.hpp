#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_mlf_distance_weight.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfDistanceWeight &msg) ;
    ApolloperceptionlidarMlfDistanceWeight from_json_ApolloperceptionlidarMlfDistanceWeight (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarMlfDistanceWeight from_json<ApolloperceptionlidarMlfDistanceWeight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfDistanceWeight &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfDistanceWeight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfDistanceWeight & dt);
}
