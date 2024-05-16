#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_ccrf_type_fusion_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarCcrfTypeFusionConfig &msg) ;
    ApolloperceptionlidarCcrfTypeFusionConfig from_json_ApolloperceptionlidarCcrfTypeFusionConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarCcrfTypeFusionConfig from_json<ApolloperceptionlidarCcrfTypeFusionConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarCcrfTypeFusionConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarCcrfTypeFusionConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarCcrfTypeFusionConfig & dt);
}
