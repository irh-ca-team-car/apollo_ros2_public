#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_transformer_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_plugin_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappTransformerParam &msg) ;
    ApolloperceptioncameraappTransformerParam from_json_ApolloperceptioncameraappTransformerParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappTransformerParam from_json<ApolloperceptioncameraappTransformerParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappTransformerParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappTransformerParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappTransformerParam & dt);
}
