#pragma once
#include "apollo_msgs/msg/obs_feature_fc_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/dense_parameter.hpp"
#include "adapter/serialization/apollo_msgs/activation_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ObsFeatureFCParameter &msg) ;
    ObsFeatureFCParameter from_json_ObsFeatureFCParameter (nlohmann::json obj) ;
    template <>
    ObsFeatureFCParameter from_json<ObsFeatureFCParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ObsFeatureFCParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ObsFeatureFCParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ObsFeatureFCParameter & dt);
}
