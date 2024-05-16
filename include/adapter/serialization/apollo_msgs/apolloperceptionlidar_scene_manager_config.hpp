#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_scene_manager_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarSceneManagerConfig &msg) ;
    ApolloperceptionlidarSceneManagerConfig from_json_ApolloperceptionlidarSceneManagerConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarSceneManagerConfig from_json<ApolloperceptionlidarSceneManagerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarSceneManagerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarSceneManagerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarSceneManagerConfig & dt);
}
