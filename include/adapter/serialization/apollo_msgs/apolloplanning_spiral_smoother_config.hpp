#pragma once
#include "apollo_msgs/msg/apolloplanning_spiral_smoother_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSpiralSmootherConfig &msg) ;
    ApolloplanningSpiralSmootherConfig from_json_ApolloplanningSpiralSmootherConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningSpiralSmootherConfig from_json<ApolloplanningSpiralSmootherConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSpiralSmootherConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSpiralSmootherConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSpiralSmootherConfig & dt);
}
