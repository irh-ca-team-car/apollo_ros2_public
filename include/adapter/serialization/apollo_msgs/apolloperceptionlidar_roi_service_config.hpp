#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_roi_service_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarROIServiceConfig &msg) ;
    ApolloperceptionlidarROIServiceConfig from_json_ApolloperceptionlidarROIServiceConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarROIServiceConfig from_json<ApolloperceptionlidarROIServiceConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarROIServiceConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarROIServiceConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarROIServiceConfig & dt);
}
