#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_ground_service_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarGroundServiceConfig &msg) ;
    ApolloperceptionlidarGroundServiceConfig from_json_ApolloperceptionlidarGroundServiceConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarGroundServiceConfig from_json<ApolloperceptionlidarGroundServiceConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarGroundServiceConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarGroundServiceConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarGroundServiceConfig & dt);
}
