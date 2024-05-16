#pragma once
#include "apollo_msgs/msg/apolloprediction_obstacle_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionObstacleConf &msg) ;
    ApollopredictionObstacleConf from_json_ApollopredictionObstacleConf (nlohmann::json obj) ;
    template <>
    ApollopredictionObstacleConf from_json<ApollopredictionObstacleConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionObstacleConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionObstacleConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionObstacleConf & dt);
}
