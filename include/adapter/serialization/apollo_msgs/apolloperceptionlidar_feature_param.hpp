#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_feature_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarFeatureParam &msg) ;
    ApolloperceptionlidarFeatureParam from_json_ApolloperceptionlidarFeatureParam (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarFeatureParam from_json<ApolloperceptionlidarFeatureParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarFeatureParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarFeatureParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarFeatureParam & dt);
}
