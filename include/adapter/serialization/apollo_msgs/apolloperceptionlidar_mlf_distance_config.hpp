#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_mlf_distance_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_mlf_distance_weight.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfDistanceConfig &msg) ;
    ApolloperceptionlidarMlfDistanceConfig from_json_ApolloperceptionlidarMlfDistanceConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarMlfDistanceConfig from_json<ApolloperceptionlidarMlfDistanceConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfDistanceConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfDistanceConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfDistanceConfig & dt);
}
