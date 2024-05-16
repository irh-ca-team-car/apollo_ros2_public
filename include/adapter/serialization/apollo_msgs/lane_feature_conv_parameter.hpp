#pragma once
#include "apollo_msgs/msg/lane_feature_conv_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/conv1d_parameter.hpp"
#include "adapter/serialization/apollo_msgs/activation_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const LaneFeatureConvParameter &msg) ;
    LaneFeatureConvParameter from_json_LaneFeatureConvParameter (nlohmann::json obj) ;
    template <>
    LaneFeatureConvParameter from_json<LaneFeatureConvParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, LaneFeatureConvParameter &dt);
    std::ostream & operator<<(std::ostream & os, const LaneFeatureConvParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const LaneFeatureConvParameter & dt);
}
