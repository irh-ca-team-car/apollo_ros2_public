#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_smoke_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_model_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_network_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_nms_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeSmokeParam &msg) ;
    ApolloperceptioncamerasmokeSmokeParam from_json_ApolloperceptioncamerasmokeSmokeParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerasmokeSmokeParam from_json<ApolloperceptioncamerasmokeSmokeParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeSmokeParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeSmokeParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeSmokeParam & dt);
}
