#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_n_cut_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarNCutConfig &msg) ;
    ApolloperceptionlidarNCutConfig from_json_ApolloperceptionlidarNCutConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarNCutConfig from_json<ApolloperceptionlidarNCutConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarNCutConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarNCutConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarNCutConfig & dt);
}
