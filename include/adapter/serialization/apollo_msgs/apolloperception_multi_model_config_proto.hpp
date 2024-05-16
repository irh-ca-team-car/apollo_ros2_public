#pragma once
#include "apollo_msgs/msg/apolloperception_multi_model_config_proto.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_model_config_proto.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionMultiModelConfigProto &msg) ;
    ApolloperceptionMultiModelConfigProto from_json_ApolloperceptionMultiModelConfigProto (nlohmann::json obj) ;
    template <>
    ApolloperceptionMultiModelConfigProto from_json<ApolloperceptionMultiModelConfigProto>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionMultiModelConfigProto &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionMultiModelConfigProto & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionMultiModelConfigProto & dt);
}
