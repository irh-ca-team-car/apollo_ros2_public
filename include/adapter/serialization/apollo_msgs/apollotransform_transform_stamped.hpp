#pragma once
#include "apollo_msgs/msg/apollotransform_transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollotransform_transform.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotransformTransformStamped &msg) ;
    ApollotransformTransformStamped from_json_ApollotransformTransformStamped (nlohmann::json obj) ;
    template <>
    ApollotransformTransformStamped from_json<ApollotransformTransformStamped>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollotransformTransformStamped &dt);
    std::ostream & operator<<(std::ostream & os, const ApollotransformTransformStamped & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotransformTransformStamped & dt);
}
