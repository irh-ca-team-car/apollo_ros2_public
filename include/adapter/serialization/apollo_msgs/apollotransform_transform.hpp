#pragma once
#include "apollo_msgs/msg/apollotransform_transform.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_quaternion.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotransformTransform &msg) ;
    ApollotransformTransform from_json_ApollotransformTransform (nlohmann::json obj) ;
    template <>
    ApollotransformTransform from_json<ApollotransformTransform>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollotransformTransform &dt);
    std::ostream & operator<<(std::ostream & os, const ApollotransformTransform & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotransformTransform & dt);
}
