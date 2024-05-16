#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_spp_engine_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarSppEngineConfig &msg) ;
    ApolloperceptionlidarSppEngineConfig from_json_ApolloperceptionlidarSppEngineConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarSppEngineConfig from_json<ApolloperceptionlidarSppEngineConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarSppEngineConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarSppEngineConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarSppEngineConfig & dt);
}
