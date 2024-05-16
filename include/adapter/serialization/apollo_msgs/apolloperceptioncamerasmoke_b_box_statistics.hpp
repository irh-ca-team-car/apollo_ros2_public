#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_b_box_statistics.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeBBoxStatistics &msg) ;
    ApolloperceptioncamerasmokeBBoxStatistics from_json_ApolloperceptioncamerasmokeBBoxStatistics (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerasmokeBBoxStatistics from_json<ApolloperceptioncamerasmokeBBoxStatistics>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeBBoxStatistics &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeBBoxStatistics & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeBBoxStatistics & dt);
}
