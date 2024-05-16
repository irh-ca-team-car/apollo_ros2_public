#pragma once
#include "apollo_msgs/msg/cruise_model_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/lane_feature_conv_parameter.hpp"
#include "adapter/serialization/apollo_msgs/max_pool1d_parameter.hpp"
#include "adapter/serialization/apollo_msgs/avg_pool1d_parameter.hpp"
#include "adapter/serialization/apollo_msgs/obs_feature_fc_parameter.hpp"
#include "adapter/serialization/apollo_msgs/classify_parameter.hpp"
#include "adapter/serialization/apollo_msgs/regress_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const CruiseModelParameter &msg) ;
    CruiseModelParameter from_json_CruiseModelParameter (nlohmann::json obj) ;
    template <>
    CruiseModelParameter from_json<CruiseModelParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, CruiseModelParameter &dt);
    std::ostream & operator<<(std::ostream & os, const CruiseModelParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const CruiseModelParameter & dt);
}
