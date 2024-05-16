#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_mlf_engine_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfEngineConfig &msg) ;
    ApolloperceptionlidarMlfEngineConfig from_json_ApolloperceptionlidarMlfEngineConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarMlfEngineConfig from_json<ApolloperceptionlidarMlfEngineConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfEngineConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfEngineConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfEngineConfig & dt);
}
