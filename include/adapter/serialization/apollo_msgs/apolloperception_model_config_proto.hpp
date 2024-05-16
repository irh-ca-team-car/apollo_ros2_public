#pragma once
#include "apollo_msgs/msg/apolloperception_model_config_proto.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_int.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_string.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_double.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_float.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_bool.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_int.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_string.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_double.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_float.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_bool.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionModelConfigProto &msg) ;
    ApolloperceptionModelConfigProto from_json_ApolloperceptionModelConfigProto (nlohmann::json obj) ;
    template <>
    ApolloperceptionModelConfigProto from_json<ApolloperceptionModelConfigProto>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionModelConfigProto &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionModelConfigProto & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionModelConfigProto & dt);
}
