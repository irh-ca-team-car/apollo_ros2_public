#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_map_manager_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMapManagerConfig &msg) ;
    ApolloperceptionlidarMapManagerConfig from_json_ApolloperceptionlidarMapManagerConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarMapManagerConfig from_json<ApolloperceptionlidarMapManagerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMapManagerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMapManagerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMapManagerConfig & dt);
}
