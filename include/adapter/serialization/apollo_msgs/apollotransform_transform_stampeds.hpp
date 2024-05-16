#pragma once
#include "apollo_msgs/msg/apollotransform_transform_stampeds.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollotransform_transform_stamped.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotransformTransformStampeds &msg) ;
    ApollotransformTransformStampeds from_json_ApollotransformTransformStampeds (nlohmann::json obj) ;
    template <>
    ApollotransformTransformStampeds from_json<ApollotransformTransformStampeds>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollotransformTransformStampeds &dt);
    std::ostream & operator<<(std::ostream & os, const ApollotransformTransformStampeds & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotransformTransformStampeds & dt);
}
