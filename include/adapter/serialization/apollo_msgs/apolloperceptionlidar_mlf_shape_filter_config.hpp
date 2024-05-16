#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_mlf_shape_filter_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfShapeFilterConfig &msg) ;
    ApolloperceptionlidarMlfShapeFilterConfig from_json_ApolloperceptionlidarMlfShapeFilterConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarMlfShapeFilterConfig from_json<ApolloperceptionlidarMlfShapeFilterConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfShapeFilterConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfShapeFilterConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfShapeFilterConfig & dt);
}
