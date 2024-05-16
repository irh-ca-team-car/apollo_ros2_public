#pragma once
#include "apollo_msgs/msg/apolloprediction_list_frame_env.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_frame_env.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionListFrameEnv &msg) ;
    ApollopredictionListFrameEnv from_json_ApollopredictionListFrameEnv (nlohmann::json obj) ;
    template <>
    ApollopredictionListFrameEnv from_json<ApollopredictionListFrameEnv>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionListFrameEnv &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionListFrameEnv & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionListFrameEnv & dt);
}
