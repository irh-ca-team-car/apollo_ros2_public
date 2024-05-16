#pragma once
#include "apollo_msgs/msg/apolloprediction_frame_env.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_history.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionFrameEnv &msg) ;
    ApollopredictionFrameEnv from_json_ApollopredictionFrameEnv (nlohmann::json obj) ;
    template <>
    ApollopredictionFrameEnv from_json<ApollopredictionFrameEnv>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionFrameEnv &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionFrameEnv & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionFrameEnv & dt);
}
